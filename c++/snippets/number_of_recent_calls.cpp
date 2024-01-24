#include <queue>

using namespace std;

// This is not my solution
// https://leetcode.com/problems/number-of-recent-calls/solutions/4161604/easy-c-solution/?envType=study-plan-v2&envId=leetcode-75
// I did not know how to create it
class RecentCounter {
public:
  RecentCounter() {}

  queue<int> q;

  int ping(int t) {

    q.push(t);

    while (q.front() < t - 3000) {
      q.pop();
    }

    return q.size();
  }
};
