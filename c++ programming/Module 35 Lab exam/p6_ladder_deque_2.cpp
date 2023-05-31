#include <bits/stdc++.h>
using namespace std;

void print( deque<int> d ) {
   for( int i=0; i<d.size(); i++ ) {
      cout<<d[i]<<" ";
   }
   cout<<"\n";
}

void _sort( int arr[],int n ) {
   deque<int> dq;

   dq.push_front( arr[0] );
   //cout<<"Size : "<< dq.size()<<"\n";

   for( int i=1; i<n; i++ ) {
      if( dq.front() < arr[i] && dq.back() > arr[i] ) {
         int prv = dq.front();
         dq.pop_front();
         dq.push_front(arr[i]);
         dq.push_front(prv);
      } else if( dq.front() > arr[i] ) {
         cout<<"Push front = "<<arr[i]<<"\n";
         dq.push_front( arr[i] );
      } else if( dq.back() < arr[i] ) {
         cout<<"Push back = "<<arr[i]<<"\n";
         dq.push_back( arr[i] );
      }
   }
   cout<<"Size : "<< dq.size()<<"\n";
   print( dq );
}

int main() {
   int n;
   cin>>n;

   int a[n];
   for( int i=0; i<n; i++ )
      cin>>a[i];

   _sort( a, n );
   return 0;
}
