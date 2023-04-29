#include <bits/stdc++.h>
using namespace std;

/*
- state: stone(n) -> cost of reaching n-th stone from first stone
- recurrence relation: 
  stone(n) = min(cost(n-1) + abs(h[n] - h[n-1]), cost(n-2) + abs(h[n] - h[n-2]))

- base case: stone(1) = 0
*/
const int N = 1e5 + 5;
const int INF = 2e9;
int h[N], dp[N];
int n, k;


int stone_2(int n) {
  dp[1] = 0;

  for (int i = 2; i <= n; i++) {
   dp[i]= INF;
    for (int j = 1; j <= k; j++) {
      if(i-j < 1)
        break;

      int new_ans = dp[i-j] + abs(h[i] - h[i-j]);
      dp[i] = min(dp[i], new_ans);
    }
  }

  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;

  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  for (int i = 1; i<=n; i++) {
    dp[i] = -1;
  }

  cout << stone_2(n) << "\n";

  return 0;
}