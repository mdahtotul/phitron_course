// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;
#define br "\n";
typedef long long ll;

int main() {
  int n, sum = 0;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
  }

  vector<int> dp(sum+1, 0);
  set<int> distinctSums;

  dp[0] = 1;
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += nums[i];
    for (int val = total; val >= nums[i]; val--) {
      if(dp[val - nums[i]] && !dp[val]) {
        dp[val] = 1;
        distinctSums.insert(val);
      }
    }
  }

  cout << distinctSums.size() << br;
  for (auto num: distinctSums) {
    cout << num << " ";
  }

  return 0;
}