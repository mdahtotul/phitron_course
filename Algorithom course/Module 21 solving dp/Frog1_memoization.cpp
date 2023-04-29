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
  if(n==1)
    return 0;

  if(dp[n] != -1){
    return dp[n];
  }

  int ans1 = stone(n - 1) + abs(h[n - 1] - h[n]);

  if(n == 2) {
    dp[n] = ans1;
    return ans1;
  }

  int ans2 = stone(n - 2) + abs(h[n - 2] - h[n]);
  int ans = min(ans1, ans2);

  dp[n] = ans;
  return ans;
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