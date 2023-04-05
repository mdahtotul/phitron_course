// https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long int y) {
      long long int x = y;
      long long int ans = 0;
      if (x < 0)
        return false;
      else
      {
        long long int i = 0;
        while (x > 0)
        {
          if(i>0) {
            ans = (x % 10) + (ans * 10);
          } else {
            ans = (x % 10) + ans ;
          }
          x /= 10;
          i++;
        }
      }

      if(y==ans)
        return true;
      else
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long int x = 998765432;
    cout << Solution().isPalindrome(x) << "\n";
}