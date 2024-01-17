#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    // This is chatGPT power
    int n = nums.size();

    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return nums[0];
    }

    // dp[i] represents the maximum amount of money that can be robbed up to
    // house i
    std::vector<int> dp(n, 0);

    // Base cases
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    // Iterate through the houses starting from the third one
    for (int i = 2; i < n; ++i) {
      // The maximum amount of money at each house is the maximum of two
      // options:
      // 1. Rob the current house and add the money robbed from the house two
      // steps before.
      // 2. Skip the current house and take the maximum amount robbed so far.
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
  }
  int rob_2(vector<int> &nums) {
    // This is a topvoted solution
    int n = nums.size();
    // Two variables to store the previous results.
    int prevFirst = 0;
    int prevSecond = 0;

    for (int i = 0; i < n; i++) {
      int temp = prevFirst;
      prevFirst = max(prevSecond + nums[i], prevFirst);
      prevSecond = temp;
    }
    return prevFirst;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> input = {183, 219, 57,  193, 94,  233, 202, 154, 65,  240,
                       97,  234, 100, 249, 186, 66,  90,  238, 168, 128,
                       177, 235, 50,  81,  185, 165, 217, 207, 88,  80,
                       112, 78,  135, 62,  228, 247, 211,};
  int answer = tester.rob_2(input);
  cout << "This answer: |" << answer << "|" << endl;
  return 0;
}
