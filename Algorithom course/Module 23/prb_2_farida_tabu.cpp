#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
long long dp[N];
 
long long coin(long long arr[], int n) {
  dp[0] = arr[0];
  dp[1] = max(arr[0], arr[1]);
 
  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
  }
  return dp[n - 1];
}
 
int main() {
 
  int T;
  cin >> T;
 
  for (int i = 1; i <= T; i++) {
    int n;
    cin >> n;
    long long arr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    cout << "Case " << i << ": " << coin(arr, n) << "\n";
  }
} 