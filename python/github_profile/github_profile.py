__author__ = "Benjamin Jorgensen"

import requests


class Github_profile(object):
    """Main string for Github_profile"""

    def __init__(self, user_name):
        super(Github_profile, self).__init__()
        self.user_name = user_name
        self.raw_user_data = self.request_data()
        self.raw_user_data_keys = self.raw_user_data.keys()

        # from here is just parsing the data
        self.login = self.check_filter("login")
        self.id = self.check_filter("id")
        self.node_id = self.check_filter("node_id")
        self.avatar = self.check_filter("avatar_url")
        self.gravatar_id = self.check_filter("gravatar_id")
        self.api_url = self.check_filter("url")
        self.html_url = self.check_filter("html_url")
        self.followers_url = self.check_filter("followers_url")
        self.following_url = self.check_filter("following_url")
        self.gists_url = self.check_filter("gists_url")
        self.starred_url = self.check_filter("starred_url")
        self.subscriptions_url = self.check_filter("subscriptions_url")
        self.organization_url = self.check_filter("organization_url")
        self.repos_url = self.check_filter("repos_url")
        self.events_url = self.check_filter("events_url")
        self.received_events_url = self.check_filter("received_events_url")
        self.type_user = self.check_filter("type")
        self.site_admin = self.check_filter("site_admin")
        self.name = self.check_filter("name")
        self.company = self.check_filter("company")
        self.blog = self.check_filter("blog")
        self.location = self.check_filter("location")
        self.email = self.check_filter("email")
        self.hireable = self.check_filter("hireable")
        self.bio = self.check_filter("bio")
        self.twitter_username = self.check_filter("twitter_username")
        self.public_repos = self.check_filter("public_repos")
        self.public_gists = self.check_filter("public_gists")
        self.followers = self.check_filter("followers")
        self.following = self.check_filter("following")
        self.created_at = self.check_filter("created_at")
        self.updated_at = self.check_filter("updated_at")

    def check_filter(self, key_word):
        if key_word in self.raw_user_data_keys:
            return self.raw_user_data[key_word]
        else:
            return "KeyError"

    def request_data(self):
        r = requests.get(f"https://api.github.com/users/{self.user_name}")
        return r.json()

    def raw_user_data_access(self):
        return self.raw_user_data

    def getLogin(self):
        return self.login


class Main:
    my_profile = Github_profile("benmi3")
    raw_user_data_ = my_profile.raw_user_data_access()
    email = my_profile.avatar
    clean_name = my_profile.html_url
    print(clean_name.split("/"))


if __name__ == "__main__":
    Main()
