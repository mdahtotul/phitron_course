#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int dp[N];

int operations(int n) {
  if(n == 1) return 0;
  if(dp[n] != -1) return dp[n];
  int ans = INF;
  if(n % 3 == 0) ans = min(ans, operations(n/3));
  if(n % 2 == 0) ans = min(ans, operations(n/2));
  ans = min(ans, operations(n-1));
  dp[n] = ans + 1;
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