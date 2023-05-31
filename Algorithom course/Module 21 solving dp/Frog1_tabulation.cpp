#include <bits/stdc++.h>
using namespace std;

/*
- state: stone(n) -> cost of reaching n-th stone from first stone
- recurrence relation: 
  stone(n) = min(cost(n-1) + abs(h[n] - h[n-1]), cost(n-2) + abs(h[n] - h[n-2]))

- base case: stone(1) = 0
*/
const int N = 1e5 + 5;
int h[N];
int dp[N];

int stone(int n) {
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    int ans1 = dp[i - 1] + abs(h[i] - h[i - 1]);
    if(i==2) {
      dp[i] = ans1;
      continue;
    }
    int ans2 = dp[i - 2] + abs(h[i] - h[i - 2]);
    dp[i] = min(ans1, ans2);
  }

  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  for (int i = 1; i<=n; i++) {
    dp[i] = -1;
  }

  cout << stone(n) << "\n";

  return 0;
}