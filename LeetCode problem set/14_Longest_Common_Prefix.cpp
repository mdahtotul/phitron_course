// https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    if ( n == 0) return ans;
    int firstLen = strs[0].size(), lastLen = strs[n - 1].size();
    for (int i = 0; i < min(firstLen, lastLen); i++) {
      if(strs[0][i] != strs[n-1][i]) {
        return ans;
      }
      ans += strs[0][i];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<string> strs = {"flower","flow","flight"};
  cout << sol.longestCommonPrefix(strs) << endl;
  return 0;
}