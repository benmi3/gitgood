from django.shortcuts import render

from .models import Question

# Create your views here.
from django.http import HttpResponse, HttpRequest
from django.template import loader


def index(request: HttpRequest):
    print(request.method)
    latest_question_list = Question.objects.order_by("-pub_date")
    template = loader.get_template("polls/index.html")
    context = {"latest_question_list": latest_question_list}
    return HttpResponse(template.render(context, request))


def detail(request: HttpRequest, question_id: int) -> HttpResponse:
    print(request)
    return HttpResponse(b"You're looking at the question." % question_id)


def results(request: HttpRequest, question_id: int) -> HttpResponse:
    print(request)
    response = b"You're looking at the results of questions %s."
    return HttpResponse(response % question_id)


def vote(request: HttpRequest, question_id: int) -> HttpResponse:
    print(request)
    return HttpResponse(b"You're voting on question %s." % question_id)
