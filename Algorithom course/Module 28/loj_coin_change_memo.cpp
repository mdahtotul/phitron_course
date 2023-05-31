// https://lightoj.com/problem/coin-change-ii

/*
  - state: dp(n, k) -> number of ways to make sum=k from coins 1 to n without crossing limit
  - recurrence: dp(n, k) = dp(n - 1, k) + 
                           dp(n-1, k - coins[n]) + 
                           dp(n - 1, k - 2 * coins[n]) + ... +
                           dp(n - 1, k - limit[n] * coins[n])
  - base case: dp(0, 0) = 1
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 60, M = 1001, MOD=100000007;

int dp[N][M];
int coins[N], limit[N];

int coinChange(int n, int k) {
  // base case
  if(n == 0) {
    if(k == 0) return 1;
    return 0;
  }

  // use memoization data
  if(dp[n][k] != -1) return dp[n][k];

  // recursive relation
  int ans = coinChange(n - 1, k);

  for (int i = 1; i <= limit[n]; i++) {
    if(k - i * coins[n] < 0) break;
    int val = coinChange(n - 1, k - i * coins[n]);
    ans = (ans + val) % MOD;
  }

  dp[n][k] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t, tst = 0;
  cin >> t;


  while(t--) {
    int n, k;
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++){
      cin >> coins[i];
    }

    for (int i = 1; i <= n; i++){
      cin >> limit[i];
    }

    cout << "Case " << ++tst << ": " << coinChange(n, k) << "\n";
  }


  return 0;
}

/*
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1

*/