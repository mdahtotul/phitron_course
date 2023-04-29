#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int operations(int n) {
  vector<int> dp(n+1);
  dp[1] = 0;
  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1] + 1;
    if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
    if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));

  cout << operations(n) << "\n";
  return 0;
}