// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;

/*
  - state: return the max of robbedMoney;
  - recurrence relation: 
      robbedMoney(nums, n) = max{
                                  robbedMoney(nums, n-2) + nums[n],
                                  robbedMoney(nums, n-1)
                                }
  - base case: n<0 -> return 0;
               n==0 -> return nums[0]
*/

class Solution {
public:
    int dp[1000];
    int robbedMoneyMemo(vector<int>& nums, int n) {

      if(n < 0)
        return 0;
      if(n == 0)
        return nums[0];

      if(dp[n] != -1)return dp[n];

      int include = robbedMoneyMemo(nums, n - 2) + nums[n];
      int exclude = robbedMoneyMemo(nums, n - 1);

      cout<<"include -> "<<include<<" exclude -> "<<exclude<<"\n";

      dp[n] = max(include, exclude);
      return dp[n];
    }

    int rob(vector<int>& nums) {
      int n = nums.size();
      memset(dp, -1, sizeof(dp));
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
      // return robbedMoneyMemo(nums, n-1);
      return max(robbedMoneyMemo(first, n-2), robbedMoneyMemo(second, n-2));
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  vector<int> n = {2,3,2};
  vector<int> n = {1,2,3};
  Solution s;
  cout << s.rob(n) << "\n";

  return 0;
}