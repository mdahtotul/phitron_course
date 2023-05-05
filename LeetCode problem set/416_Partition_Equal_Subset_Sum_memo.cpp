// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;

/*
 - state: fun(n, target) -> return 1 if we can make target using numbers 1 to n
 - recurrence relation:
     fun(n=0, target) = fun(n + 1, target) || fun(n + 1, target - nums[n])
  - base_case: fun(0, target) = 1 if target == 0 else 0
*/

class Solution {
public:
    int8_t dp[201][10001];
    bool canPartition(vector<int>& nums) {
      memset(dp, -1, sizeof(dp));
      int totalSum = 0;
      for (int num : nums) {
        totalSum += num;
      }
      if (totalSum % 2 != 0)
        return false;

      return subsetSum(nums, totalSum / 2);
    }
    bool subsetSum(vector<int>& nums, int target, int i=0) {
      if(target == 0)
        return true;
      if(i >= size(nums) || target < 0)
        return false;
      if(dp[i][target] != -1)
        return dp[i][target];
      return dp[i][target] = subsetSum(nums, target - nums[i], i + 1) || subsetSum(nums, target, i + 1);
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