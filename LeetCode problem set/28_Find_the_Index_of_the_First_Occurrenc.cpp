// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
      if(needle.size() > haystack.size()) return -1;
      int len = haystack.size() - needle.size() + 1;
      for (int i = 0; i < len; i++){
        for (int j = 0; j < needle.size(); j++) {
          if(haystack[i+j] != needle[j]) break;
          else if(j== needle.size()-1) return i;
        }
      }
      return -1;
    }
};

int main() {
  Solution s;
  string haystack = "hello";
  string needle = "ll";
  cout << s.strStr(haystack, needle) << endl;
  return 0;
}
