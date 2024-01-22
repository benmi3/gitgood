#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    string t_ = "";
    for (int i = 0; i < t.length(); ++i) {
      size_t x = s.find_first_of(t[i]);
      if (x != string::npos) {
        t_ = t_ + t[i];
        s = s.erase(x, x + 1);
      }
    }
    size_t y = t_.find(s);
    if (y != string::npos) {
      return true;
    } else {
      return false;
    }
  }

  bool isSubsequence2(string s, string t) {
    vector<int> s_;
    string t_ = "";
    string s__ = s;
    for (int i = 0; i < t.length(); ++i) {
      size_t x = s.find_last_of(t[i]);
      size_t xx = t.find_first_of(t[i]);
      if (x != string::npos) {
        t_ = t_ + t[i];
        s = s.erase(x, x + 1);
        t = t.erase(0, i);

        s_.push_back(x);
      }
    }
    size_t y = t_.find(s__);
    if (y != string::npos) {
      return true;
    } else {
      if (t.find(s__) != string::npos)
        return true;
      for (int a = 1; a < s_.size(); ++a)
        if (s_[a - 1] > s_[a])
          return false;
      return false;
    }
  }

  bool isSubsequence3(string s, string t) {
    cout << "-------------" << endl;
    string t_ = "";
    string s__ = s;
    int i = 0;
    while (s.length() > 0) {
      cout << s << "/://" << t << endl;
      size_t x = t.find_first_of(s[0]);
      size_t xx = s.find_first_of(s[0]);
      if (x != string::npos) {
        cout << t_ << endl;
        t_ = t_ + s[i];
        t = t.erase(x, x + 1);
        s = s.erase(0, 1);
      } else {
        return false;
      }
    }
    size_t y = t_.find(s__);
    if (y != string::npos && s__ == t_) {
      return true;
    } else {
      return false;
    }

    return false;
  }

  bool isSubsequence4(string s, string t) {
    cout << "-------------" << endl;
    string t_ = "";
    string s__ = s;
    int i = 0;
    while (s.length() > 0) {
      cout << s << "/://" << t << endl;
      size_t x = t.find_first_of(s[0]);
      size_t xx = s.find_first_of(s[0]);
      if (x != string::npos) {
        if (t[0] == s[0]) {
          t_ = t_ + s[i];
          t = t.erase(x, x + 1);
          s = s.erase(0, 1);
        } else {
          t.erase(0, 1);
        }
      } else {
        return false;
      }
    }
    size_t y = t_.find(s__);
    if (y != string::npos && s__ == t_) {
      return true;
    } else {
      return false;
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  cout << "start --" << endl;
  cout << tester.isSubsequence4("abc", "ahbgdc") << endl;
  cout << "start --" << endl;
  cout << tester.isSubsequence4("axc", "ahbgdc") << endl;
  cout << "start --" << endl;
  cout << tester.isSubsequence4("aaaaaa", "bbaaaa") << endl;
  cout << "start --" << endl;
  cout << tester.isSubsequence4("ab", "baab") << endl;
  cout << "start --" << endl;
  cout << tester.isSubsequence4("acb", "ahbgdc") << endl;
  return 0;
}
