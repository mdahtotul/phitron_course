// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
/*
  - state: f(n, m) -> number of unique paths from (0, 0) to (n, m)
  - recurrence relation: f(n, m) -> f(n-1, m) + f(n, m-1)
  - base case: f(0, 0) = 1
*/

const int N = 101;
int dp[N][N];

class Solution {
public:
    int getPaths(int row, int col) {
      // base case
      if(row == 0 && col == 0) return 1;

      // check if already calculated
      if(dp[row][col] != -1) return dp[row][col];

      // calculate result from smaller sub-problems
      int ans = 0;
      if(row > 0)
        ans += getPaths(row - 1, col);
      if(col > 0)
        ans += getPaths(row, col - 1);

      dp[row][col] = ans; // memoize
      return ans;
    }
    int uniquePaths(int m, int n) {
      memset(dp, -1, sizeof(dp));
      return getPaths(m - 1, n - 1);
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  Solution s;
  int m = 3, n = 7;
  cout<<s.uniquePaths(m, n)<<"\n";

  return 0;
}
