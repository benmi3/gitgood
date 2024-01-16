#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer;
    for (int x = 1; x <= n; ++x) {
      string z;
      cout << "Start ---- x: " << x << endl;
      if (x % 3 == 0) {
        cout << "x%3 = " << x % 3 << endl;
        z = "Fizz";
        if (x % 5 == 0) {
          cout << "x%5 = " << x % 5 << endl;
          z = z + "Buzz";
        }
      } else if (x % 5 == 0) {
        cout << "x%5 = " << x % 5 << endl;
        z = "Buzz";
      } else {
        z = to_string(x);
      }

      answer.push_back(z);
      z = "";
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<string> answer = tester.fizzBuzz(5);
  cout << "Answer" << endl;
  for (auto &x : answer) {
    cout << x << endl;
  }
  return 0;
}
