#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_area(int a, int b, int x, int y) {
  int tmp;
  int res = 0;
  if (a > b) {
    tmp = b;
  } else {
    tmp = a;
  }
  res = tmp * (x - y);
  // cout << "res: " << res << endl;
  return res;
};

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int tmp = 0;
    for (int x = 0; x < height.size(); ++x) {
      cout << height[x] << endl;
      if (x < height.size() / 2) {
        if (height[x] - x > num1) {
          num1 = height[x];
          num2 = x;
        }
      } else {
        if (height[x] + x > num3) {
          num3 = height[x];
          num4 = x;
        }
      }
      if (num1 > num3) {
        tmp = num3;
      } else {
        tmp = num1;
      }
      cout << "Num1: " << num1 << endl;
      cout << "Num2: " << num2 << endl;
      cout << "Num3: " << num3 << endl;
      cout << "Num4: " << num4 << endl;
      cout << "Max: " << max << endl;
      if (tmp * num4 - num2 > max)
        max = tmp * (num4 - num2);
    }
    return max;
  }

  int maxArea2(vector<int> &height) {
    int max = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int tmp = 0;
    int temp1 = 0;
    int maybe_max = 0;
    float potato = 0;
    /*
      if (height.size() == 2) {
        if (height[0] > height[1]) {
          return height[1];
        } else {
          return height[0];
        }
      }*/
    if (height.size() < 5) {
      potato = 2;
    } else {
      potato = 1.5;
    }
    for (int x = 0; x < height.size(); ++x) {
      temp1 = x / static_cast<float>(height.size());
      if (x < height.size() / potato) {
        if (height[x] + temp1 > num1) {
          num1 = height[x];
          num2 = x;
        }
      } else {
        if (check_area(num1, height[x], x, num2) >
            check_area(num1, num3, num4, num2)) {
          num3 = height[x];
          num4 = x;
        }
      }
      maybe_max = check_area(num1, num3, num4, num2);
      if (maybe_max > max)
        max = maybe_max;
      cout << "Num1: " << num1 << " Num2: " << num2 << " Num3: " << num3
           << " Num4: " << num4 << " Max: " << max << endl;
    }
    if (max < check_area(height[0], num3, num4, 0))
      return check_area(height[0], num3, num4, 0);
    return max;
  }

  int maxArea3(vector<int> &height) {
    // This works, but is slow
    /*
    int max = 0;
    int tmp = 0;
    int dis = 0;
    for (int x = 0; x < height.size() - 1; ++x) {
      // Outer
      for (int y = x + 1; y < height.size(); ++y) {
        // Inner
        dis = y - x;
        if (height[x] > height[y]) {
          tmp = height[y] * dis;
        } else {
          tmp = height[x] * dis;
        }
        if (tmp > max) {
          max = tmp;
        }
      }
    }
    */
    int num_big = 0;
    int num_big1 = 0;
    int num_big2 = 0;
    int num_ind = 0;
    int num_ind1 = 0;
    int num_ind2 = 0;
    for (int x = 0; x < height.size() - 1; ++x) {
      if (height[x] > num_big1) {
        num_big2 = num_big1;
        num_ind2 = num_ind1;
        num_big1 = height[x];
        num_ind1 = x;
      } else if (height[x] > num_big2) {
        num_big2 = height[x];
        num_ind2 = x;
      }
    }
    if (num_big1 > num_big2) {
      num_big = num_big2;
    } else {
      num_big = num_big1;
    }

    if (num_ind1 > num_ind2) {
      num_ind = num_ind1 - num_ind2;
    } else {
      num_ind = num_ind2 - num_ind1;
    }

    return num_big * num_ind;
    // return max;
  }

  int maxArea1(vector<int> &height) {
    // gpt optimized
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
      int h = min(height[left], height[right]);
      int w = right - left;
      int area = h * w;
      maxArea = max(maxArea, area);

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxArea;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> val1 = {1, 2, 4, 3};
  vector<int> val2 = {1, 2, 1};
  vector<int> val3 = {1, 8, 100, 2, 100, 4, 8, 3, 7};
  vector<int> val4 = {1, 8, 6, 2, 5, 4, 8, 25, 7};
  vector<int> val5 = {2, 3, 4, 5, 18, 17, 6};
  vector<int> val6 = {8, 20, 1, 2, 3, 4, 5, 6};
  int a1 = tester.maxArea1(val1);
  int a2 = tester.maxArea1(val2);
  int a3 = tester.maxArea1(val3);
  int a4 = tester.maxArea1(val4);
  int a5 = tester.maxArea1(val5);
  int a6 = tester.maxArea1(val6);
  cout << "A1: " << a1 << endl;
  cout << "A2: " << a2 << endl;
  cout << "A3: " << a3 << endl;
  cout << "A4: " << a4 << endl;
  cout << "A5: " << a5 << endl;
  cout << "A6: " << a6 << endl;
  /*
  A1: 4
  A2: 2
  A3: 200
  A4: 49
  A5: 17
  A6: 42
    */

  return 0;
}
