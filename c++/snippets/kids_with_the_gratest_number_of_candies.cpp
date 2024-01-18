#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    vector<bool> answers;
    int max = *max_element(candies.begin(), candies.end());
    for (int x : candies) {
      if (x + extraCandies >= max) {
        answers.push_back(true);
      } else {
        answers.push_back(false);
      }
    }
    return answers;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> candies = {2, 3, 5, 1, 3};
  int extra_candies = 3;
  vector<bool> answers = tester.kidsWithCandies(candies, extra_candies);
  for (bool x : answers) {
    cout << "Answer: " << x << endl;
  }
  return 0;
}
