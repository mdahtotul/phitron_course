// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;

/*
  - state: return the minimum number of perfect square numbers that sum to n;
  - recurrence relation: 
      robbedMoney(n) = 1 + robbedMoney(n- (i*i)) for all i from 1 to sqrt(n)
  - base case: robbedMoney(0) -> return 0;
*/

class Solution {
public:
    int dp[1005];
    int robbedMoneyTab(vector<int>& nums) {
      int n = nums.size();
      if(n == 0)
        return 0;
      if(n == 1)
        return nums[0];
      if(n == 2)
        return max(nums[0], nums[1]);
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);

      for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }
      return dp[n-1];
    }

    int rob(vector<int>& nums) {
      int n = nums.size();
      memset(dp, 0, sizeof(dp));
      if(n == 1)
        return nums[0];

      vector<int> first, second;
      for (int i = 0; i < n; i++) {
        if(i != n-1) {
          first.push_back(nums[i]);
        } 
        if(i != 0) {
          second.push_back(nums[i]);
        }
      }
      
      return max(robbedMoneyTab(first), robbedMoneyTab(second));
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  // vector<int> n = {2,3,2};
  // vector<int> n = {1,2,3};
  vector<int> n = {1,2,3,1};
  Solution s;
  cout << s.rob(n) << "\n";

  return 0;
}