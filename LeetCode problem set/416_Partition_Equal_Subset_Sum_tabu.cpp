// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int8_t dp[202][10002];
    bool canPartition(vector<int>& nums) {
      memset(dp, 0, sizeof(dp));
      int totalSum = 0;
      for (int num : nums) {
        totalSum += num;
      }
      if (totalSum % 2 != 0)
        return false;
      int n = size(nums);
      return subsetSumTab(nums, totalSum / 2, n);
    }
    bool subsetSumTab(vector<int>& nums, int target, int n) {
      dp[0][0] = 1;
      for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

      for (int i = n - 1; i >= 0; i--){
        for (int tar = 0; tar<= target; tar++) {
          int include = 0;
          if(tar >= nums[i])
            include = dp[i + 1][tar - nums[i]];
          
          int exclude = dp[i + 1][tar];

          dp[i][tar] = include || exclude;
        }
      }

      return dp[0][target];
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  Solution s;
  vector<int> nums = {1, 5, 11, 5};
  // vector<int> nums = {1, 2, 5, 3};
  cout<<s.canPartition(nums)<<"\n";
  return 0;
}