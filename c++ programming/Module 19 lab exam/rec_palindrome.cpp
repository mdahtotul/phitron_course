#include <bits/stdc++.h>
using namespace std;

int check_palindrome( string str, int i, int n ) {
   if( i>=n )
      return 1;

   if( str[i] != str[n] )
      return false;

   return check_palindrome( str, i+1, n-1 );
}

bool is_pal( string str, int n ) {
   return check_palindrome( str, 0, n-1 );
}

int main() {

   ios_base::sync_with_stdio( 0 );
   cin.tie( 0 );

   string s;
   cin>>s;

   //empty string is considered as palindrome
   int n = s.size();
   if( n == 0 ) {
      cout<<"Yes";
      return 0;
   }
   is_pal( s, n ) ? cout<<"Yes" : cout<<"No";

   return 0;
}
