#include <bits/stdc++.h>
using namespace std;

vector<int> merge_arr( vector<int>a, vector<int>b, int len ) {
   vector<int>c;
   int idxA=0, idxB=0;
   /**
      @TimeComplexity: O(n+m); Because len = n + m;
   */
   for( int i=0; i<len; i++ ) {
      if( idxA == a.size() ) {
         c.push_back( b[idxB] );
         idxB++;
      } else if( idxB == b.size() ) {
         c.push_back( a[idxA] );
         idxA++;
      } else if( a[idxA] > b[idxB] ) {
         // cout<<a[idxA]<<" <-Arr A & Arr B-> "<<b[idxB]<<"\n";
         c.push_back( a[idxA] );
         idxA++;
      } else if( a[idxA] <= b[idxB] ) {
         // cout<<a[idxA]<<" <-Arr A & Arr B-> "<<b[idxB]<<"\n";
         c.push_back( b[idxB] );
         idxB++;
      }
   }

   return c; // returning merged & sorted array
}

int main() {
   int n, m;
   cin>>n;
   vector<int> a( n ), b( k );
   for( int i=0; i<n; i++ )
      cin>>a[i];

   cin>>m;
   for( int i=0; i<k; i++ )
      cin>>b[i];
   int len = n + m;
   vector<int> ans = merge_arr( a, b, len );
   for( int i=0; i<ans.size(); i++ )
      cout<<ans[i]<<" ";
   return 0;
}
