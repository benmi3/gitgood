#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseVowels1(string s) {
    // char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    string vowels = "aeiouyAEIOUY";
    vector<int> index;
    int counter = 0;
    for (char x : s) {
      if (vowels.find(x) != string::npos) {
        index.push_back(counter);
      }
      ++counter;
    }
    char y1;
    char y2;
    while (index.size() >= 2) {
      y1 = s[index.front()];
      y2 = s[index.back()];

      s[index.front()] = y2;
      s[index.back()] = y1;

      index.pop_back();
      index.erase(index.begin());
      cout << index.size() << endl;
    }
    return s;
  }

  string reverseVowels(string s) {
        string vo = "aeiouAEIOU";
        string* v = &vo;
        size_t found = s.find_first_of(*v);
        size_t found_b = s.find_last_of(*v);
        while (found != string::npos && found_b != string::npos) {
            char in = s[found];
            s[found] = s[found_b];
            s[found_b] = in;
            found = s.find_first_of(*v, found + 1);
            found_b = s.find_last_of(*v, found_b - 1);
            if (found >= found_b)
                break;
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
  Solution tester;
  string x = tester.reverseVowels("hello");
  cout << "Answer: " << x << endl;
  return 0;
}
