from django.contrib import admin

# Register your models here.
from .models import Comment


class CommentAdmin(admin.ModelAdmin):
    # fields = ["pub_date", "question_text"]
    fieldset = [
        (None, {"fields": ["question_text"]}),
        ("Date Information", {"fields": ["pub_date"]}),
    ]
    list_display = ["question_text", "pub_date", "was_published_recently"]
    list_filter = ["pub_date"]
    search_fields = ["question_text"]


admin.site.register(Comment, CommentAdmin)
