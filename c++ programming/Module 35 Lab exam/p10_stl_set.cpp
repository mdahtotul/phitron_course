#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   set<int> st;

   for( int i=0; i<n; i++ ) {
      int val;
      cin>>val;
      st.insert( val );
   }
   int k;
   cin>>k;

   for( int i=0; i<k; i++ ) {
      int val;
      cin>>val;
      st.insert( val );
   }
   for(auto i: st)
      cout<<i<<" ";
   cout<<"\n";

   return 0;
}
