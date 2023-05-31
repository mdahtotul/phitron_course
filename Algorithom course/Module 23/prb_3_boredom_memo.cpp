#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long dp[N], arr[N];

long long boredom(long long val) {
  if(val == 0)
    return 0;

  if(val == 1)
    return dp[1];

  long long val1, val2;
  val1 = boredom(val-2)+(val*dp[val]);
  val2 = boredom(val-1);

  return max(val1, val2);
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