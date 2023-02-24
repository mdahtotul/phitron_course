#include <bits/stdc++.h>
using namespace std;

int main() {
   string str;
   cin>>str;

   stack<char> st;

   for( int i=0; i<str.size(); i++ ) {

      char ch = str[i];

      if( ch == '(' || ch == '{' || ch == '[' )
         st.push( ch );
      else {
         if( st.empty() ) {
            cout<<"No\n";
            return 0;
         }
         if( ( st.top() == '(' && ch == ')' ) || ( st.top() == '{' && ch == '}' ) || ( st.top() == '[' && ch == ']' ) )
            st.pop();
         else {
            cout<<"No";
            return 0;
         }
      }
   }

   if( st.empty() ) {
      cout<<"Yes\n";
   } else {
      cout<<"No\n";
   }
   return 0;
}


