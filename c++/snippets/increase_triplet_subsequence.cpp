#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool increasingTriplet(std::vector<int> &nums) {
    int i, j, k;
    for (int x = 2; x < nums.size(); ++x) {
      i = nums[x - 2];
      j = nums[x - 1];
      k = nums[x];
      cout << "i: " << i << endl;
      cout << "j: " << j << endl;
      cout << "k: " << k << endl;
      if (i < j && j < k) {
        return true;
      }
    }
    return false;
  }

  bool increasingTriplet(std::vector<int> &nums) {
    // Solution
    if (nums.size() < 3) {
      return false;
    }
    int a = INT_MAX;
    int b = INT_MAX;

    for (int num : nums) {
      if (num <= a) {
        a = num;
      } else if (num <= b) {
        b = num;
      } else {
        return true;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> nums = {20, 100, 10, 12, 5, 13};
  bool y = tester.increasingTriplet(nums);
  cout << y << endl;
  return 0;
}
