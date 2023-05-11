// https://lightoj.com/problem/coin-change-i

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

void coinChange(int n, int k, int tst) {
  // base case
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int target = 0; target <= k; target++) {
      // recursive relation
      dp[i][target] = dp[i - 1][target];

      for (int j = 1; j <= limit[i]; j++) {
        if(target - j * coins[i] < 0) break;
        int val = dp[i - 1][target - j * coins[i]];
        dp[i][target] = (dp[i][target] + val) % MOD;
      }
    }
  }

  cout << "Case " << tst << ": " << dp[n][k] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t, tst = 0;
  cin >> t;


  while(t--) {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
      cin >> coins[i];
    }

    for (int i = 1; i <= n; i++){
      cin >> limit[i];
    }

    memset(dp, 0, sizeof(dp));
    tst++;
    coinChange(n, k, tst);
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