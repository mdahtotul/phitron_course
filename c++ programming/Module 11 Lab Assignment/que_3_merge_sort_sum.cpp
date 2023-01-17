#include <bits/stdc++.h>
using namespace std;

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
      idxA++;
      idxT++;
   }

   while( idxB<n2 ) {
      arr[idxT] = b[idxB];
      idxB++;
      idxT++;
   }
}

void mergeSort( int arr[], int left, int right ) {
   if( left<right ) {
      int mid = ( left+right )/2;

      mergeSort( arr, left, mid );
      mergeSort( arr, mid+1, right );

      _merge( arr, left, mid, right );
   }
}

int main() {
   int n, k;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++)
      cin>>arr[i];
   cin>>k;

   mergeSort( arr, 0, n-1 );

   int low=0, high=n-1, pairs=0;
   while(low<high)
   {
      int sum = arr[low] + arr[high];
      if(sum == k)
      {
         pairs++; low++; high--;
      }
      else if(sum > k)
         high--;
      else
         low++;

   }
   cout<<pairs;
   return 0;
}
