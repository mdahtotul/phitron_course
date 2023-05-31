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

int subset_sum(int n, int target) {
  if(n==0) {
    if(target == 0) {
      return 1;
    } else {
      return 0;
    }
  }

  if(dp[n][target] != -1) return dp[n][target];

  int ans1 = subset_sum(n - 1, target);
  if(target < nums[n]) {
    dp[n][target] = ans1;
    return ans1;
  }
  int ans2 = subset_sum(n - 1, target - nums[n]);

  int ans = ans1 || ans2;

  dp[n][target] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, target;
  cin >> n >> target;

  memset(dp, -1, sizeof(dp));

  for(int i=1; i<=n; i++) {
    cin >> nums[i];
  }

  cout<<subset_sum(n, target)<<"\n";
  return 0;
}

/*
6 9
3 34 4 12 5 2
target = 9
*/