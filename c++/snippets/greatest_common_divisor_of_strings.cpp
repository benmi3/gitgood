#include <iostream>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    string answer = "";
    if (str1.find(str2) == string::npos)
      return "";
    if (str1.compare(str1.find(str2), str2.length(), str2) == str1.find(str2)) {
      int length_ = str1.find(str2) + str2.length();
      answer = str1.replace(str1.find(str2), length_, "");
    }

    return answer;
  }
  string gcdOfStrings2(string str1, string str2) {
    // Check if concatenated strings are equal or not, if not return ""
    if (str1 + str2 != str2 + str1)
      return "";
    // If strings are equal than return the substring from 0 to gcd of
    // size(str1), size(str2)
    return str1.substr(0, gcd(str1.size(), str2.size()));
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  string answer1 = tester.gcdOfStrings2("ABCABC", "ABC");
  cout << "This answer: |" << answer1 << "|" << endl;
  string answer2 = tester.gcdOfStrings2("ABABAB", "ABAB");
  cout << "This answer: |" << answer2 << "|" << endl;
  string answer3 = tester.gcdOfStrings2("LEET", "CODE");
  cout << "This answer: |" << answer3 << "|" << endl;
  return 0;
}
