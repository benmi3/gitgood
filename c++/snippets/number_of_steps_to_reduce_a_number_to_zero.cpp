#include <iostream>
using namespace std;

class Solution {
public:
  int numbersOfSteps(int num) {
    int answer = 0;
    int y = num;
    for (int x = 1; x != 0; ++x) {
      cout << "Y:" << y << endl;
      if (y == 0) {
        break;
      }
      answer = x;
      if (y % 2 == 0) {
        y = y / 2;
        continue;
      } else {
        y = y - 1;
        continue;
      }
      // answer = x;
      // if (y == 0) {
      //  break;
      //}
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  int answer = tester.numbersOfSteps(14);
  cout << "Answer:" << answer << endl;
  return 0;
}
