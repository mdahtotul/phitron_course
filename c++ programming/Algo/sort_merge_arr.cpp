#include <bits/stdc++.h>
using namespace std;

void _merge( int arr[], int left, int mid, int right ) {
   int n1 = mid-left+1;
   int n2 = right-mid;

   int a[n1], b[n2]; // temp arrays

   for( int i=0; i<n1; i++ )
      a[i] = arr[left + i];

   for( int i=0; i<n2; i++ )
      b[i] = arr[mid+1+i];

   int idxA=0, idxB=0, idxT=left;
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

void mergeSort( int arr[], int left, int right ) {
   if( left < right ) {
      int len = left + right;
      int mid = len/2;
      mergeSort( arr, left, mid );
//      for(int i=0; i<mid; i++)
//         cout<<arr[i]<<" ";
//         cout<<"<--left && right--> ";
//      for(int i=mid; i<right; i++)
//         cout<<arr[i]<<" ";
//      cout<<"\n";
      mergeSort( arr, mid+1, right );

      _merge( arr, left, mid, right );
   }
}

int main() {

   int arr[] = {5,8,7,6,3};
   int size = sizeof( arr ) / sizeof( arr[0] );
   mergeSort( arr, 0, size-1 );
   for( int i=0; i<5; i++ )
      cout<<arr[i]<<" ";

   cout<<"\n";
   return 0;
}
