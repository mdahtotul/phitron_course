// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int dp[N];

class Solution {
public:
    int fib(int n) {
      if(n==0)
        return 0;
      else if(n<=2)
        return 1;

      if(dp[n] > 0)
        return dp[n];

      return dp[n] = fib(n-1) + fib(n-2);
    }
};

int main () {
  Solution s;
  cout << s.fib(8) << endl;
  return 0;
}