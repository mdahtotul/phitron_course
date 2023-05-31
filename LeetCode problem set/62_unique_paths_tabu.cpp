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
    int uniquePaths(int row, int col) {
      
      // base case
      dp[0][0] = 1;

      // dp[0][1], dp[0,2], dp[1][0], dp[2][0]
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if(i==0 && j==0)
            continue;

          int ans = 0;
          if(i > 0) ans += dp[i-1][j];
          if(j > 0) ans += dp[i][j-1];

          dp[i][j] = ans; // memoize
        }
      }

      return dp[row-1][col-1];
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  Solution s;
  int m = 3, n = 7;
  cout<<s.uniquePaths(m, n)<<"\n";

  return 0;
}
