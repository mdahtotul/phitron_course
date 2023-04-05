// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans(2);
    unordered_map<int, int> hash_table;
    for (int i = 0; i < nums.size(); i++) {
      auto it = hash_table.find(target - nums[i]);
      if(it != hash_table.end()) {
        return {it->second, i};
      }

      hash_table[nums[i]] = i;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  vector<int> nums = {2,7,11,15};
  int target = 26;
  vector<int> ans = Solution().twoSum(nums, target);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}

/*
Example 1:
-----------
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
-----------
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
-----------
Input: nums = [3,3], target = 6
Output: [0,1]
*/