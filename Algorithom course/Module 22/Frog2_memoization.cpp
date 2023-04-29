#include <bits/stdc++.h>
using namespace std;

/*
- state: stone(n) -> cost of reaching n-th stone from first stone
- recurrence relation: 
  stone(n) = for i=1 to k: 
    min(cost(n-i) + abs(h[n] - h[n-i]))

- base case: stone(1) = 0
*/
const int N = 1e5 + 5;
const int INF = 2e9;
int h[N], dp[N];
int n, k;

int stone_2(int n) {
  if(n==1)
    return 0;

  if(dp[n] != -1)
    return dp[n];

  int ans = INF;
  for (int i = 1; i <= k; i++) {
    if(n-i < 1)
      break;
      
    int new_ans = stone_2(n-i) + abs(h[n] - h[n-i]);
    ans = min(ans, new_ans);
  }

  dp[n] = ans;
  return ans;
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