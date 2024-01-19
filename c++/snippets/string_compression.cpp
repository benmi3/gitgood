#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    vector<char> result;
    char prev_c = ' ';
    int counter = 0;
    vector<int> backwards;
    for (int i = 0; i <= chars.size(); ++i) {
      if (i > 0) {
        if (chars[i] != prev_c) {
          result.push_back(prev_c);
          if (counter > 10) {
            int big_num = counter;
            while (big_num > 0) {
              int smaller_num = big_num % 10;
              backwards.push_back(smaller_num);
              big_num /= 10;
            }
            reverse(backwards.begin(), backwards.end());
            for (int x : backwards)
              result.push_back('0' + x);
            backwards.clear();
          } else if (counter > 1) {
            result.push_back('0' + counter);
          }
          counter = 0;
        }
      }
      ++counter;
      prev_c = chars[i];
    }
    chars = result;
    return chars.size();
  }
  int compressgpt(vector<char> &chars) {
    // same as above, but chatgpt refactored it
    // and fixed a mistake that I cant find.
    if (chars.empty()) {
      return 0;
    }

    vector<char> result;
    char prev_c = chars[0];
    int counter = 1;

    for (int i = 1; i <= chars.size(); ++i) {
      if (i < chars.size() && chars[i] == prev_c) {
        ++counter;
      } else {
        result.push_back(prev_c);

        if (counter > 1) {
          string count_str = to_string(counter);
          result.insert(result.end(), count_str.begin(), count_str.end());
        }

        counter = 1;
        prev_c = (i < chars.size()) ? chars[i] : ' ';
      }
    }

    chars = result;
    return chars.size();
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  // vector<char> testvalue = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  vector<char> testvalue = {
      'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
  };
  // vector<char> testvalue = {'a'};
  for (char x : testvalue)
    cout << x << endl;
  int answer = tester.compress(testvalue);
  cout << "answer:" << answer << endl;
  for (auto x : testvalue)
    cout << "|" << x << "|" << endl;
  return 0;
}
