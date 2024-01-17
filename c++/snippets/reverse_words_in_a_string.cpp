#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string answer;
    string y;
    for (char x : s) {
      // cout << "X: |" << x << "|--" << endl;
      if (x == ' ') {
        if (y != "") {
          cout << "I will add this to the list: |" << y << "|--" << endl;
          answer = y + " " + answer;
        }
        y = "";
      } else {
        y = y + x;
      }
      cout << "Y: |" << y << "|--" << endl;
    }
    answer = y + " " + answer;

    cout << "Answer: |" << answer << "|" << endl;
    while (answer[0] == ' ') {
      if (answer[0] == ' ')
        answer = answer.substr(1);
      else
        break;
    }
    cout << "Answer after 1: |" << answer << "|" << endl;

    while (answer[answer.length() - 1] == ' ') {
      if (answer[answer.length() - 1] == ' ')
        answer.pop_back();
      else
        break;
    }

    cout << "Answer after 2: |" << answer << "|" << endl;
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  string answer = tester.reverseWords("example   good a");
  cout << "This answer: |" << answer << "|" << endl;
  return 0;
}
