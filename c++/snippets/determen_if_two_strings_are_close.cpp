#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1 == word2)
      return true;
    bool result;
    int counter = 0;
    cout << "/" << endl;
    for (char x : word2) {
      cout << "X: " << x << " Result: " << result << endl;
      size_t found = word1.find_first_of(x);
      if (found != string::npos) {
        cout << found << endl;
        // aa
      }
      ++counter;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  cout << "A: " << tester.closeStrings("abc", "bca") << endl;

  return 0;
}
