// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

const int N = 1002;
int dp[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      char ch;
      cin >> ch;
      if(ch == '.') {
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        if((i==1) && (j==1)) {
          dp[i][j] = 1;
        }
      } else {
        dp[i][j] = 0;
      }
    }
  }

  cout << dp[n][n] << "\n";

  return 0;
}

/*
4
....
.*..
...*
*...
*/

