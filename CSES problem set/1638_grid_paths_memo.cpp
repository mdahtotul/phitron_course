// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

const int N = 1002;
int dp[N][N];
char grid[N][N];

int pathMemo(int x, int y) {
  if(x < 1 || y < 1) return 0;

  if(grid[x][y] == '*') {
    dp[x][y] = 0;
    return 0;
  }

  if(x == 1 && y ==1) {
    dp[x][y] = 1;
    return 1;
  }

  if(dp[x][y] != -1) {
    return dp[x][y];
  }

  int ans = 0;
  if(x > 1) {
    ans += pathMemo(x - 1, y);
  }
  if(y>1) {
    ans += pathMemo(x, y - 1);
  }
  return dp[x][y] = ans % MOD;
}


int solve(int x, int y) {
  if(x < 1 || y < 1) return 0;
  if(grid[x][y] == '*') {
    dp[x][y] = 0;
    return 0;
  }
  if(x == 1 && y == 1) {
    return 1;
  }
  if(dp[x][y] != -1) {
    return dp[x][y];
  }
  int ans = 0;
  if(x > 1) {
    ans += solve(x-1, y);
  }
  if(y > 1) {
    ans += solve(x, y-1);
  }
  return dp[x][y] = ans % MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++){
    string str;
    cin >> str;
    for (int j = 1; j <= n; j++){
      grid[i][j] = str[j-1];
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << pathMemo(n, n) << "\n";
  
  return 0;
}

/*
4
....
.*..
...*
*...
*/

