from django.contrib import admin

# Register your models here.
from .models import Choice, Question


# class ChoiceInLine(admin.StackedInline): # Might change to later
class ChoiceInLine(admin.TabularInline):
    # Using inline would only make sens if
    # its using a foreign key
    model = Choice
    extra = 3


class QuestionAdmin(admin.ModelAdmin):
    # fields = ["pub_date", "question_text"]
    fieldset = [
        (None, {"fields": ["question_text"]}),
        ("Date Information", {"fields": ["pub_date"]}),
    ]
    inlines = [ChoiceInLine]  # Declared class above
    list_display = ["question_text", "pub_date", "was_published_recently"]
    list_filter = ["pub_date"]
    search_fields = ["question_text"]


admin.site.register(Question, QuestionAdmin)

admin.site.register(Choice)
