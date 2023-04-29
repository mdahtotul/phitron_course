#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N], arr[N];

int sz;

long long coin(int n) {
  if(n >= sz)
    return 0;

  if(dp[n] != -1)
    return dp[n];

  dp[n] = max(coin(n + 1), coin(n + 2) + arr[n]);
  return dp[n];
}

int main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> sz;
    memset(dp, -1, sizeof(dp));
    
    for (int j = 0; j < sz; j++) {
      cin >> arr[j];
    }
    
    cout << "Case " << i << ": " << coin(0) << "\n";
  }
  return 0;
}

/*
Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10
*/