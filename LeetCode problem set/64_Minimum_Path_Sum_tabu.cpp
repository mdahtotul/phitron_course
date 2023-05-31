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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int row = grid.size();
      int col = grid[0].size();

      for (int i = 1; i < row; i++) 
        grid[i][0] += grid[i-1][0];
        
      for (int j = 1; j < col; j++) 
        grid[0][j] += grid[0][j-1];

      // loop through all possible states
      for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
          // calculate result from smaller sub-problems
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
      }
      return grid[row - 1][col - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    cout << s.minPathSum(grid) << "\n";

    return 0;
}