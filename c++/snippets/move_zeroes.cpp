#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int zero_counter = 0;
    for (int x = 0; x < nums.size(); ++x) {
      nums[x - zero_counter] = nums[x];
      if (x + zero_counter >= nums.size()) {
        nums[x] = 0;
        zero_counter = zero_counter - 1;
      }
      if (nums[x] == 0) {
        ++zero_counter;
      }
    }
  }

  void moveZeroesgpt(vector<int> &nums) {
    int zero_counter = 0;
    for (int x = 0; x < nums.size(); ++x) {
      if (nums[x] != 0) {
        nums[x - zero_counter] = nums[x];
        if (zero_counter > 0) {
          nums[x] = 0;
        }
      } else {
        ++zero_counter;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  cout << "main" << endl;
  Solution tester;
  vector<int> nums1 = {0, 1, 0, 3, 12};
  vector<int> nums2 = {0};
  vector<int> nums3 = {0, 1, 0};
  vector<int> nums4 = {0, 0, 0, 0, 0, 0, 1, 1, 1};
  tester.moveZeroes(nums1);
  tester.moveZeroes(nums2);
  tester.moveZeroes(nums3);
  tester.moveZeroes(nums4);
  cout << "-----------------------" << endl;
  for (int x : nums1)
    cout << "X: " << x << endl;
  cout << "-----------------------" << endl;
  for (int x : nums2)
    cout << "Y: " << x << endl;
  cout << "-----------------------" << endl;
  for (int x : nums3)
    cout << "Z: " << x << endl;
  cout << "-----------------------" << endl;
  for (int x : nums4)
    cout << "Z: " << x << endl;
  return 0;
}
