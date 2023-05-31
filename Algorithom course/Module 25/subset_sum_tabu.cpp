#include <bits/stdc++.h>
using namespace std;

/*
 - state: fun(n, target) -> return 1 if we can make target using numbers 1 to n
 - recurrence relation:
     fun(n, target) = fun(n - 1, target) || fun(n - 1, target - nums[n])
  - base_case: fun(0, target) = 1 if target == 0 else 0
*/

const int N = 102;
const int M = 1e5 + 5;

int dp[N][M], nums[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, target;
  cin >> n >> target;

  for(int i=1; i<=n; i++) {
    cin >> nums[i];
  }

  // base case
  dp[0][0] = 1;
  for (int i = 1; i <= target; i++){
    dp[0][i] = 0;
  }

  // loop over the states
  for (int i = 1; i <= n; i++) {
    for (int tar = 1; tar<=target; tar++) {
      int ans1 = dp[i-1][tar];
      if(tar < nums[i]) {
        dp[i][tar] = ans1;
      } else {
        int ans2 = dp[i-1][tar - nums[i]];
        dp[i][tar] = ans1 || ans2; // dp[i][tar] = dp[i-1][tar] || dp[i-1][tar - nums[i]
      }
    }
  }

  cout << dp[n][target] << "\n";
  return 0;
}

/*
6 9
3 34 4 12 5 2
target = 9
*/