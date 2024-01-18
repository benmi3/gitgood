#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int counter = 0;
    int counter_0 = 0;
    if (flowerbed.size() == 1)
      if (flowerbed[0] == 0)
        return true;
    for (int i = 0; i < flowerbed.size(); ++i) {
      if (flowerbed[i] == false) {
        ++counter_0;
        if (i == 1)
          if (counter_0 >= 2) {
            ++counter;
            counter_0 = 1;
          }
        if ( i + 1 == flowerbed.size())
          if (counter_0 >= 2) {
            ++counter;
            counter_0 = 1;
          }
        if (counter_0 >= 3) {
          ++counter;
          counter_0 = 1;
        }
      } else {
        counter_0 = 0;
      }
    }
    if (counter >= n) {
      return true;
    } else {
      return false;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<int> flowerbed = {0, 0, 1, 0, 1};
  int n = 1;
  bool x = tester.canPlaceFlowers(flowerbed, n);
  cout << "Answer: " << x << endl;
  return 0;
}
