#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> answer;
    for (int x = 0; x < nums.size(); x++) {
      cout << "Outer; " << x << endl;
      for (int y = 0; y < nums.size(); y++) {
        cout << "Inner; " << y << endl;
        if (x == y) {
          continue;
        }
        if (answer.empty()) {
          if (nums[x] + nums[y] == target) {
            cout << "X:" << x << "Y:" << y << endl;
            answer.push_back(x);
            answer.push_back(y);
          }
        }
      }
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  // vector<int> nums = {2, 7, 11, 15};
  vector<int> nums = {3, 2, 4};
  vector<int> answer = tester.twoSum(nums, 6);
  cout << "This answer:" << endl;
  for (int &i : answer) {
    cout << i << endl;
  }
  return 0;
}
