#include <bits/stdc++.h>
using namespace std;

void _merge( int arr[], int low, int mid, int high ) {
   int n1 = mid+1-low;
   int n2 = high-mid;
   int a[n1], b[n2];

   for( int i=0; i<n1; i++ )
      a[i] = arr[low+i];

   for( int i=0; i<n2; i++ )
      b[i] = arr[mid+1+i];

   int idxA=0, idxB=0, idxT=low;

   while( idxA < n1 && idxB < n2 ) {
      if( a[idxA] < b[idxB] ) {
         arr[idxT] = a[idxA];
         idxA++;
         idxT++;
      } else {
         arr[idxT] = b[idxB];
         idxB++;
         idxT++;
      }
   }

   while( idxA < n1 ) {
      arr[idxT] = a[idxA];
      idxA++;
      idxT++;
   }

   while( idxB < n2 ) {
      arr[idxT] = b[idxB];
      idxB++;
      idxT++;
   }
}

void mergeSort( int arr[], int low, int high ) {
   if( low<high ) {
      int len = low+high;
      int mid = len/2;

      mergeSort( arr, low, mid );
      mergeSort( arr, mid+1, high );
      _merge( arr, low, mid, high );
   }
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for( int i=0; i<n; i++ )
      cin>>arr[i];

   mergeSort( arr, 0, n-1 );
   for( int i=0; i<n; i++ ) {
      if( arr[i-1]!=arr[i] )
         cout<<arr[i]<<" ";
   }

   cout<<"\n";
   return 0;
}
