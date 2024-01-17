#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string answer;
    int maxi;
    if (word1.length() > word2.length()) {
      cout << "word1 is bigger" << endl;
      maxi = word1.length();
    } else {
      cout << "word2 is bigger" << endl;
      maxi = word2.length();
    }
    cout << "Maxi is: " << maxi << endl;
    for (int i = 0; i < maxi; ++i) {
      if (i < word1.length()) {
        answer = answer + word1[i];
      }
      if (i < word2.length()) {
        answer = answer + word2[i];
      }
      // cout << answer << endl;
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  string answer = tester.mergeAlternately("abc", "pqr");
  cout << "This answer:" << answer << endl;
  return 0;
}
