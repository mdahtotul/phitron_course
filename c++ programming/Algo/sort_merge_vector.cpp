#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort( vector<int>a ) {
   int len = a.size();
   // base case
   if( len<=1 )
      return a;

   vector<int> b, c;
   int mid = len/2;
   int i=0;
   // dividing elements
   for( i=0; i<mid; i++ )
      b.push_back( a[i] );

   for( i=mid; i<len; i++ )
      c.push_back( a[i] );

   vector<int> sorted_b = merge_sort( b );
   vector<int> sorted_c = merge_sort( c );
   // merging elements
   vector<int> sorted_a;
   int idxB=0, idxC=0;

   for( i=0; i<len; i++ ) {
      if( idxB == sorted_b.size() ) {
         sorted_a.push_back( sorted_c[idxC] );
         idxC++;
      } else if( idxC == sorted_c.size() ) {
         sorted_a.push_back( sorted_b[idxB] );
         idxB++;
      } else if( sorted_b[idxB] <= sorted_c[idxC] ) {
         sorted_a.push_back( sorted_b[idxB] );
         idxB++;
      } else {
         sorted_a.push_back( sorted_c[idxC] );
         idxC++;
      }
   }
   return sorted_a;
}

int main() {
   vector<int> a = {3,5,4,8,6,9};
   vector<int>ans = merge_sort( a );
   for( int i=0; i<ans.size(); i++ )
      cout<<ans[i]<<" ";

   return 0;
}
