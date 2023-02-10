#include <bits/stdc++.h>
using namespace std;

int main() {

   string s;
   cin>>s;

   deque<char> de;

   for( int i=0; i<s.size(); i++ ) {
      de.push_back( s[i] );
   }

   int pal = 1;
   if( de.size() == 1 ) {
      pal = 1;
   } else if( de.size() > 1 ) {
      while( de.size() > 1 ) {
         if( de.front() == de.back() ) {
            de.pop_back();
            de.pop_front();
         } else {
            pal = 0;
            break;
         }
      }
   }

   pal == 1 ? cout<<"Yes\n" : cout<<"No\n";

   return 0;
}
