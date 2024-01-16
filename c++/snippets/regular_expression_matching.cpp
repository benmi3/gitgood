#include <iostream>
#include <string>
using namespace std;

int index_r(int string_l, int index_c) {
  if (index_c > string_l) {
    return string_l;
  } else {
    return index_c;
  }
}

class Solution {
public:
  bool isMatch(string s, string p) {
    bool yes_check = false;
    int sl = s.length() - 1;
    int pl = p.length() - 1;
    int index_max;

    if (sl > pl) {
      index_max = sl;
    } else {
      index_max = pl;
    }

    if (s == p) {
      return true;
    }

    if (sl > pl) {
      return false;
    }

    if (sl < pl) {
      if (p.find('*') == string::npos) {
        return false;
      }
    }

    cout << "max: " << index_max << endl;
    //// Here starts the fun
    for (int i = 0; i <= index_max; ++i) {
      cout << "-------------------" << endl;
      cout << "Index: " << i << endl;
      char *s1 = &s[index_r(sl, i)];
      cout << "Check S1: " << *s1 << endl;
      char *p1 = &p[index_r(pl, i)];
      cout << "Check P1: " << *p1 << endl;
      char *p2 = &p[index_r(pl, i + 1)];
      cout << "Check P2: " << *p2 << endl;
      if (*s1 == *p1) {
        yes_check = true;
        cout << "s[index_r(sl, i)] == p[index_r(pl, i)]" << endl;
        continue;
      }
      if (*p1 == '.') {
        yes_check = true;
        cout << "p[index_r(pl, i)] == '.'" << endl;
        continue;
      }
      if (*p1 == '*') {
        yes_check = true;
        cout << "p[index_r(pl, i)] == '*'" << endl;
        continue;
      }

      if (*p2 == '*') {
        yes_check = true;
        cout << "p[index_r(pl, i + 1)] == '*'" << endl;
        continue;
      }
      cout << "I will return false" << endl;
      return false;
    }
    return yes_check;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  bool test = tester.isMatch("aaa", "ab*a");
  cout << test << endl;
  return 0;
}
