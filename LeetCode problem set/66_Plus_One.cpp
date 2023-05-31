// https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int idx = digits.size() - 1;
      for (int i = 0; i < digits.size(); i++) {
        if(digits[idx] == 9) {
          digits[idx] = 0;
          idx--;
        } else {
          digits[idx] += 1;
          return digits;
        }
      }
      digits.insert(digits.begin(), 1);
      return digits;
    }
};

int main(){
  Solution s;
  vector<int> digits = {1,9,9};
  vector<int> res = s.plusOne(digits);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}