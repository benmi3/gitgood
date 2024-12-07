from django.shortcuts import render

from .models import Question

# Create your views here.
from django.http import HttpResponse, HttpRequest, Http404


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
    print(request)
    return HttpResponse(b"You're voting on question %s." % question_id)
