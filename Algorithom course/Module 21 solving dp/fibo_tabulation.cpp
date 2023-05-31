#include <bits/stdc++.h>
using namespace std;

/*
- fib(n) -> calculates the nth fibonacci number
- fib(n) = fib(n-1) + fib(n-2)
- fib(1) = 1, fib(2) = 1
*/
const int N = 101;

int dp[N];

int fib(int n) {
  dp[1] = dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  memset(dp, -1, sizeof(dp));

  int n;
  cin >> n;
  cout << fib(n) << "\n";
  return 0;
}