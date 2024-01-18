#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    /*
    // I wanted to do it like this, but its too slow
    vector<int> result;
    vector<int> nums_copy;
    int z;
    for (int x = 0; x < nums.size(); ++x) {
        nums_copy.insert(nums_copy.begin(), nums.begin(), nums.end());
        nums_copy.erase(nums_copy.begin() + x);
        result.push_back(accumulate(nums_copy.begin(), nums_copy.end(), 1,
                       multiplies<int>()));
        nums_copy.clear();
    }
    return result;
    */
    // here comes some gpt power
    int n = nums.size();

    // Initialize the output array with the prefix products
    std::vector<int> result(n, 1);

    // Calculate the prefix products
    int prefix_product = 1;
    for (int i = 0; i < n; ++i) {
      result[i] *= prefix_product;
      prefix_product *= nums[i];
    }

    // Calculate the suffix products and update the output array
    int suffix_product = 1;
    for (int i = n - 1; i >= 0; --i) {
      result[i] *= suffix_product;
      suffix_product *= nums[i];
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> x = tester.productExceptSelf(nums);
  for (int y : x)
    cout << y << endl;
  return 0;
}
