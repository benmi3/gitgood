import datetime

from django.db import models
from django.utils import timezone
from django.contrib import admin


# Create your models here.
class Question(models.Model):
    question_text = models.CharField(max_length=200)
    pub_date = models.DateTimeField("date published")
    user_id = models.BigIntegerField(null=False, default=0)

    def __str__(self) -> str:
        # Lets turn it into an actual string before return it
        return f"{self.question_text}"

    @admin.display(boolean=True, ordering="pub_date", description="Published recently?")
    def was_published_recently(self) -> bool:
        now = timezone.now()
        return now - datetime.timedelta(days=1) <= self.pub_date <= now


class Choice(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.CharField(max_length=200)
    votes = models.IntegerField(default=0)
    # You dont have to be a user to vote
    # but need to limit revotes somehow
    ipaddress = models.GenericIPAddressField(null=True)
    user_id = models.BigIntegerField(null=True)

    def __str__(self) -> str:
        return f"{self.choice_text}"
