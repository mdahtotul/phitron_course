//https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx1=m-1, idx2=n-1, idxT=m+n-1;
    while(idx1>=0 && idx2>=0){
      if(nums1[idx1] > nums2[idx2]) {
        nums1[idxT] = nums1[idx1];
        idx1--;
        idxT--;
      } else {
        nums1[idxT] = nums2[idx2];
        idx2--;
        idxT--;
      }
    }
    while(idx2 >= 0) {
      nums1[idxT] = nums2[idx2];
      idx2--;
      idxT--;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Solution sol;
  vector<int> nums1 = {1,2,3,0,0,0};
  vector<int> nums2 = {2,5,6};
  // vector<int> nums1 = {1};
  // vector<int> nums2 = {};
  sol.merge(nums1, 3, nums2, 3);
  for(auto it: nums1)
      cout << it << " ";
}
