#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort( vector<int> a ) {
   int len = a.size();
   // base case
   if( len <= 1 )
      return a;

   vector<int> b, c;
   int mid = len/2;
   // divide
   for( int i=0; i<mid; i++ ) // run n/2 time
      b.push_back( a[i] );
   for( int i=mid; i<len; i++ ) // run n/2 time
      c.push_back( a[i] );

   vector<int> sorted_b = merge_sort( b );
   vector<int> sorted_c = merge_sort( c );

   // merge
   vector<int> sorted_a;
   int idxB=0, idxC=0, invC=0;

   for( int i=0; i<len; i++ ) {
      if( idxB == sorted_b.size() ) {
         sorted_a.push_back( sorted_c[idxC] );
         idxC++;
      } else if( idxC == sorted_c.size() ) {
         sorted_a.push_back( sorted_b[idxB] );
         idxB++;
      } else if( sorted_b[idxB] <= sorted_c[idxC] ) {
         sorted_a.push_back( sorted_b[idxB] );
         idxB++;
      } else if( sorted_b[idxB] > sorted_c[idxC] ) {
         sorted_a.push_back( sorted_c[idxC] );
         idxC++;
         invC++;
      }
   }

   return sorted_a;
}

int main() {
   int n, i;
   cin>>n;
   vector<int> a( n );
   for( i=0; i<n; i++ )
      cin>>a[i];

   vector<int> ans = merge_sort( a );
   for( i=0; i<n; i++ )
      cout<<ans[i]<<" ";

}
