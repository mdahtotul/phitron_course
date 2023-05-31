#include <bits/stdc++.h>
using namespace std;

/*
  1. knapsack(n, cap) -> maximum profit considering objects 1 to n and capacity=cap
  2. recurrence relation:
      knapsack(n, cap) = max(
                              knapsack(n-1, cap),
                              val[n] + knapsack(n-1, cap-wt[n])
                            )
  3. base_case: knapsack(0, cap) = 0
*/

const int N = 102;
const int M = 1e5 + 5;

long long dp[N][M];
int wt[N], val[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, w;
  cin >> n >> w;

  for (int j = 1; j <= n; j++) {
    cin >> wt[j] >> val[j];
  }

  for (int j = 0; j <= w; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int cap = 0; cap <= w; cap++) {
      if(cap < wt[i]) {
        dp[i][cap] = dp[i - 1][cap];
      } else {
        dp[i][cap] = max(val[i] + dp[i - 1][cap - wt[i]], dp[i - 1][cap]);
      }
    }
  }

  cout << dp[n][w] << "\n";

  return 0;
}

/*
Input:
3 8
3 30
4 50
5 60
Output:
90

Input:
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Output:
5000000000

Input:
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Output:
17
*/