import datetime

from django.db import models
from django.utils import timezone
from django.contrib import admin


# Create your models here.
class Comment(models.Model):
    comment_text = models.CharField(max_length=500)
    pub_date = models.DateTimeField("date published")
    parent_comment = models.ForeignKey("self", on_delete=models.CASCADE, null=True)

    def __str__(self) -> str:
        # Lets turn it into an actual string before return it
        return f"{self.comment_text}"

    @admin.display(boolean=True, ordering="pub_date", description="Published recently?")
    def was_published_recently(self) -> bool:
        now = timezone.now()
        return now - datetime.timedelta(days=1) <= self.pub_date <= now

    def is_child(self) -> bool:
        if self.parent_comment:
            return True
        else:
            return False
