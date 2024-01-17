#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    std::sort(magazine.begin(), magazine.end());
    std::sort(ransomNote.begin(), ransomNote.end());
    while (!ransomNote.empty()) {
      cout << "R: " << ransomNote << endl;
      cout << "M: " << magazine << endl;
      size_t found = magazine.find(ransomNote[0]);
      if (found == std::string::npos) {
        cout << "Not Found:" << found << endl;
        return false;
      } else {
        cout << "Found:" << found << endl;
        ransomNote = ransomNote.substr(1);
        magazine = magazine.substr(found + 1);
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  bool answer = tester.canConstruct("aab", "baa");
  cout << "This answer:" << answer << endl;
  return 0;
}
