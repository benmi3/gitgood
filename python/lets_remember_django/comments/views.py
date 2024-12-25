from django.db.models import F

# Create your views here.
from django.http import (
    Http404,
    HttpRequest,
    HttpResponse,
    HttpResponseRedirect,
    JsonResponse,
)
from django.shortcuts import get_object_or_404, render
from django.urls import reverse
from django.views import generic
from rest_framework.views import APIView
from django.utils import timezone
from .models import Comment


class IndexView(generic.ListView):
    template_name = "comments/index.html"
    context_object_name = "latest_question_list"

    def get_queryset(self):
        """
        Return the last five published questions (not including thos set to be published in the future)
        """
        return Comment.objects.filter(pub_date__lte=timezone.now()).order_by(
            "-pub_date"
        )[:5]


class DetailView(generic.DetailView):
    model = Comment
    template_name = "comments/detail.html"


class ResultsView(generic.DetailView):
    model = Comment
    template_name = "comments/results.html"


def vote(request: HttpRequest, comment_id: int) -> HttpResponse:
    # print(request)
    # return HttpResponse(b"You're voting on question %s." % question_id)
    req_ref = request.headers["Referer"]
    # TODO: implement this, change name from vote to postComment
    c = get_object_or_404(Comment, pk=comment_id)
    try:
        selected_choice = c.choice_set.get(pk=request.POST["chice"])
    except (KeyError, Comment.DoesNotExist):
        return render(
            request,
            "comments/detail.html",
            {"question": c, "error_message": "You didn't select a choice."},
        )
    else:
        selected_choice.votes = F("votes") + 1
        selected_choice.save()
        # You need to alwasy return an HttpReponseRedirect after successfully dealing
        # with POST data. This prevents data from being posted twice if a user
        # hits the Back button
        return HttpResponseRedirect(reverse("comments:results", args=(c.id)))


class RestTestView(APIView):
    def get(self, request):
        print(request)
        res = {"msg": "get", "who": 1}
        return JsonResponse(res)

    def post(self, request):
        print(request)
        res = {"msg": "post", "who": 2}
        return JsonResponse(res)
