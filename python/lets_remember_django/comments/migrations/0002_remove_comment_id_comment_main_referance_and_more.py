# Generated by Django 5.1.4 on 2024-12-27 11:34

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('comments', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='comment',
            name='id',
        ),
        migrations.AddField(
            model_name='comment',
            name='main_referance',
            field=models.URLField(default='https://www.benmi.me', primary_key=True, serialize=False),
        ),
        migrations.AlterField(
            model_name='comment',
            name='comment_text',
            field=models.CharField(max_length=1000),
        ),
    ]