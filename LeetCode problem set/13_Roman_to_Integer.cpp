// https://leetcode.com/problems/roman-to-integer/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  map<char, int> roman_values = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
  };
  int romanToInt(string s) {
    int count = 0;
    int i = 0;
    while(i < s.length()) {
      int num = 0;
      if(roman_values[s[i]] >= roman_values[s[i+1]]) {
        num = roman_values[s[i]];
        i++;
      } else {
        num = roman_values[s[i+1]] - roman_values[s[i]];
        i += 2;
      }
      count += num;
    }
    return count;
  };
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s = "IV";
  // Solution().romanToInt(s);
   cout << Solution().romanToInt(s) << "\n";
}

/*
Example 1:
------------
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
------------
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
-----------
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/