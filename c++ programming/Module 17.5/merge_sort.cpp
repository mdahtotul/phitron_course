#include <bits/stdc++.h>
using namespace std;

void _merge( int arr[], int low, int mid, int high ) {
   int n1 = mid-low+1;
   int n2 = high - mid;

   int a[n1], b[n2]; // temp arrays

   for( int i=0; i<n1; i++ )
      a[i] = arr[low+ i];

   for( int i=0; i<n2; i++ )
      b[i] = arr[mid+1+i];

   int idxA=0, idxB=0, idxT=low;
   while( idxA<n1 && idxB<n2 ) {
      if( a[idxA]<b[idxB] ) {
         arr[idxT]=a[idxA];
         idxT++;
         idxA++;
      } else {
         arr[idxT]=b[idxB];
         idxT++;
         idxB++;
      }
   }

   while( idxA<n1 ) {
      arr[idxT]=a[idxA];
      idxA++;
      idxT++;
   }

   while( idxB<n2 ) {
      arr[idxT]=b[idxB];
      idxT++;
      idxB++;
   }
}

void mergeSort( int arr[], int low, int high ) {
   if( low < high ) {
      int len = low + high;
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
   for( int i=0; i<n; i++ )
      cout<<arr[i]<<" ";

   cout<<"\n";
   return 0;
}
