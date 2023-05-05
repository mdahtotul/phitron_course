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

long long knapsack(int n, int cap){
  if(n == 0) return 0;

  if(dp[n][cap] != -1) return dp[n][cap];

  if(cap < wt[n]) {
    long long ans = knapsack(n - 1, cap);
    dp[n][cap] = ans;
    return ans;
  }

  long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
  long long ans2 = knapsack(n - 1, cap);

  long long ans = max(ans1, ans2);
  dp[n][cap] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, w;
  cin >> n >> w;

  for (int j = 1; j <= n; j++) {
    cin >> wt[j] >> val[j];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i][j] = -1;
    }
  }

  cout << knapsack(n, w) << "\n"; 

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