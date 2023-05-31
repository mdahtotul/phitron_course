#include <bits/stdc++.h>
using namespace std;

int isSubArr( int a[], int b[], int n, int k ) {
   int flag=0;
   int idxA=0, idxB=0;

   while( ( idxA<n ) && ( idxB<k ) ) {
      if( a[idxA] == b[idxB] ) {
         flag++;
         idxA++;
         idxB++;
      } else
         idxB++;
   }
   if( n<=k ) {
      while( idxB<k ) {
         if( a[idxA] == b[idxB] ) {
            flag++;
            idxB++;
         } else
            idxB++;
      }
      if( flag==n ) return 1;
   } else {
      while( idxA<n ) {
         if( a[idxA] == b[idxB] ) {
            flag++;
            idxA++;
         } else
            idxA++;
      }
      if( flag==k ) return 1;
   }
   return 0;
}

void _merge( int arr[], int left, int mid, int right ) {
   int n1 = mid-left+1;
   int n2 = right-mid;

   int a[n1], b[n2];
   for( int i=0; i<n1; i++ )
      a[i] = arr[left+i];
   for( int i=0; i<n2; i++ )
      b[i] = arr[mid+i+1];

   int idxA=0, idxB=0, idxT=left;
   while( ( idxA<n1 ) && ( idxB<n2 ) ) {
      if( a[idxA]<b[idxB] ) {
         arr[idxT] = a[idxA];
         idxT++;
         idxA++;
      } else {
         arr[idxT] = b[idxB];
         idxT++;
         idxB++;
      }
   }

   while( idxA<n1 ) {
      arr[idxT] = a[idxA];
      idxT++;
      idxA++;
   }

   while( idxB<n2 ) {
      arr[idxT] = b[idxB];
      idxT++;
      idxB++;
   }

}

void mergeSort( int a[], int left, int right ) {
   if( left<right ) {
      int mid = ( left+right )/2;

      mergeSort( a, left, mid );
      mergeSort( a, mid+1, right );

      _merge( a, left, mid, right );
   }
}

int main() {
   int n, k;
   cin>>n;
   int a[n];
   for( int i=0; i<n; i++ )
      cin>>a[i];
   cin>>k;
   int b[k];
   for( int i=0; i<k; i++ )
      cin>>b[i];

   mergeSort( a, 0, n-1 );
   mergeSort( b, 0, k-1 );

   isSubArr( a, b, n, k ) == 1 ? cout<<"YES": cout<<"NO";

   return 0;
}
