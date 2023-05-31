// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for (int i = 0; i < s.size(); i++) {
        char now = s[i];
        if(now == '(' || now == '{' || now == '[') {
          st.push(s[i]);
        } else {
          if(st.empty()) return false;
          if( now == ')' && st.top()=='(' )
            st.pop();
         else if( now == '}' && st.top()=='{' )
            st.pop();
         else if( now == ']' && st.top()=='[' )
            st.pop();
          else 
            return false;
        }
      }
      if(st.empty()) return true;
      else return false;
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Solution sol;
  cout<<sol.isValid("()[]{}")<<endl;
  return 0;
}