#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N], arr[N];

long long boredom(long long val) {
  dp[0] = 0;
  dp[1] = dp[1];

  for(int i = 2; i <= val; i++) {
    dp[i] = max(dp[i-1], dp[i-2]+(i*dp[i]));
  }
  
  return dp[val];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  long long n, mx=0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin>>arr[i];
    dp[arr[i]]++;
    mx = max(mx, arr[i]);
  }

  cout << boredom(mx);

  return 0;
}

/*
Input
2
1 2
Output: 2

Input
3
1 2 3
Output: 4

Input
9
1 2 1 3 2 2 2 2 3
Output: 10
*/