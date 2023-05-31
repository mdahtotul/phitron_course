// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      int prv = 1;
      int ways = 1;
      int i = 1;
      while(n > i) {
        ways += prv;
        prv = ways - prv;
        i++;
      }
      return ways;
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Solution sol;
  cout << sol.climbStairs(4) << endl;
  return 0;
}