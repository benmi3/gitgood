from django.shortcuts import render, get_object_or_404

from .models import Question, Choice

# Create your views here.
from django.http import HttpResponse, HttpRequest, Http404
from django.urls import reverse
from django.db.models import F


def index(request: HttpRequest):
    print(request.method)
    latest_question_list = Question.objects.order_by("-pub_date")
    context = {"latest_question_list": latest_question_list}
    return render(request, "polls/index.html", context)


def detail(request: HttpRequest, question_id: int) -> HttpResponse:
    try:
        question = Question.objects.get(pk=question_id)
    except Question.DoesNotExist:
        raise Http404("Question does not exist")
    return render(request, "polls/detail.html", {"question": question})


def results(request: HttpRequest, question_id: int) -> HttpResponse:
    print(request)
    response = b"You're looking at the results of questions %s."
    return HttpResponse(response % question_id)


def vote(request: HttpRequest, question_id: int) -> HttpResponse:
    # print(request)
    # return HttpResponse(b"You're voting on question %s." % question_id)
    q = get_object_or_404(Question, pk=question_id)
    try:
        selected_choice = q.choice_set.get(pk=request.POST["chice"])
    except (KeyError, Choice.DoesNotExist):
        return render(
            request,
            "polls/detail.html",
            {"question": q, "error_message": "You didn't select a choice."},
        )
    else:
        selected_choice.votes = F("votes") + 1
        selected_choice.save()
        # You need to alwasy return an HttpReponseRedirect after successfully dealing
        # with POST data. This prevents data from being posted twice if a user
        # hits the Back button
        return HttpResponse(reverse("polls:results", args=(q.id)))
