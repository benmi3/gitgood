import datetime

from django.test import TestCase
from django.urls import reverse
from django.utils import timezone

# Create your tests here.
from .models import Question


class QuestionModelTests(TestCase):
    def test_was_published_recently_with_future_question(self):
        time = timezone.now() + datetime.timedelta(days=30)
        futute_question = Question(pub_date=time)
        self.assertIs(futute_question.was_published_recently(), False)

    def test_was_published_recently_with_old_question(self):
        """
        was_published_recently() returns False for question whose pub_date
        is older then 1 day.
        """
        time = timezone.now() - datetime.timedelta(days=1, seconds=1)
        old_question = Question(pub_date=time)
        self.assertIs(old_question.was_published_recently(), False)

    def test_was_published_recently_with_recent_quesiton(self):
        """
        was_published_recently() returns for questions whose pub_date
        is within the last day.
        """
        time = timezone.now() - datetime.timedelta(hours=23, minutes=59)
        recent_question = Question(pub_date=time)
        self.assertIs(recent_question.was_published_recently(), True)


def create_question(question_text, days):
    """
    Create a question with the givn 'question_text' and publish the
    given number of 'days' offset to now (negative for questions published
    in the past, positive for question that have yet to be published
    """
    time = timezone.now() + datetime.timedelta(days=days)
    return Question.objects.create(question_text=question_text, pub_date=time)


class QuestionIndexViewTests(TestCase):
    def test_no_questions(self):
        """
        If no question exist, an appropriate message is displayed.
        """
        response = self.client.get(reverse("polls:index"))
        print(response)
        # this fails due to AttributeError: 'QuerySet' object has no attribute 'status_code'
        self.assertEqual(response.status_code, 200)
        self.assertContains(response, "No polls are available.")
        self.assertQuerySetEqual(response.context["latest_question_list"], [])

    def test_past_question(self):
        """
        Questions with a pub_date in the past are displayed on the index page.
        """
        question = create_question(question_text="Past Question.", days=-30)
        response = self.client.get(reverse("polls:index"))
        self.assertQuerySetEqual(response.context["latest_question_list"], [question])

    def test_future_question(self):
        """
        Questions with a pub_date in the future are not displayed on
        the index page.
        """
        create_question(question_text="Future question.", days=30)
        response = self.client.get(reverse("polls:index"))
        self.assertContains(response, "No polls are available.")
        self.assertQuerySetEqual(response.context["latest_question_list"], [])

    def test_future_and_past_question(self):
        """
        Even if both past and future questions exist, only past question
        are displayed.
        """
        question = create_question(question_text="Past question.", days=-30)
        create_question(question_text="Future question.", days=30)
        response = self.client.get(reverse("polls:index"))
        self.assertQuerySetEqual(response.context["latest_question_list"], [question])

    def test_five_past_questions(self):
        """
        The questions index page may display multiple questions.
        """
        futureQuestion = create_question(question_text="Future question.", days=30)
        question0 = create_question(question_text="Past question 0.", days=-31)
        question1 = create_question(question_text="Past question 1.", days=-30)
        question2 = create_question(question_text="Past question 2.", days=-29)
        question3 = create_question(question_text="Past question 3.", days=-28)
        question4 = create_question(question_text="Past question 4.", days=-27)
        question5 = create_question(question_text="Past question 5.", days=-26)
        response = self.client.get(reverse("polls:index"))
        self.assertContains(
            response.context["latest_question_list"],
            [question1, question2, question3, question4, question5],
        )
        self.assertNotContains(
            response.context["latest_question_list"], [futureQuestion, question0]
        )
