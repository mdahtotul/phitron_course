// https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;
/*
  - state: f(n, m) -> minimum path cost from (0, 0) to (n, m)
  - recurrence relation: f(n, m) -> min{
                                    f(n-1, m) + arr[n][m],
                                    f(n, m-1) + arr[n][m]
                                  }
  - base case: f(0, 0) = return arr[0][0]
*/

const int N = 201;
int dp[N][N];
const int INF = 1e9;

class Solution {
public:
    int minDistance(vector<vector<int>>& grid, int row, int col) {
      // base case
      if(row == 0 && col == 0)
        return grid[0][0];

      // check if already calculated
      if(dp[row][col] != -1)
        return dp[row][col];

      // calculate result from smaller sub-problems
      int ans = INF;
      int cost1 = INF, cost2 = INF;

      if(row > 0)
        cost1 = minDistance(grid, row - 1, col) + grid[row][col];
      if(col > 0)
        cost2 = minDistance(grid, row, col - 1) + grid[row][col];

      ans = min({ans, cost1, cost2});
      dp[row][col] = ans; // memoize
      return ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
      memset(dp, -1, sizeof(dp));
      int row = grid.size();
      int col = grid[0].size();
      
      return minDistance(grid, row-1, col-1);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    cout << s.minPathSum(grid) << "\n";

    return 0;
}