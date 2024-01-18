#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    // -----------------------------------------------
    int ns = chars.size();
    string o = "";
    for (int i = 0; i < ns; ++i) {
      //  -^-
      cout << " " << endl;
      if (o.find(chars[i] != string::npos)) {
        cout << " " << endl;
        //
        o = o + chars[i];
      } else {
        cout << " " << endl;
        o = o + chars[i];
      }
    }
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    char *end = vowel + sizeof(vowel) / sizeof(vowel[0]);
    char *position = find(vowel, end, chars[1]);

    cout << "pos:" << (position != end) << endl;
    return o.length();
  }
};

int main(int argc, char *argv[]) {
  Solution tester;
  vector<char> testvalue = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  int answer = tester.compress(testvalue);
  cout << string(testvalue.begin(), testvalue.end()) << endl;
  cout << "answer:" << answer << endl;
  return 0;
}
