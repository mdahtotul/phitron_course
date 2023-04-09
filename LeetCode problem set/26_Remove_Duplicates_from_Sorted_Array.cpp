//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/930191919/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int k = 0;
      for (int i = 1; i < nums.size(); i++){
        if(nums[k] != nums[i]){
          k++;
          nums[k]=nums[i];
        }
      }
      return k+1;
    };
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates(nums) << endl;
    return 0;
}