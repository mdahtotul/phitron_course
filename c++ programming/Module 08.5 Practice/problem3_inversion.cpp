#include <bits/stdc++.h>
using namespace std;

int _merge( int arr[], int temp[], int left, int mid, int right ) {
   int i=left, j=mid, k=left;

   int invCount = 0;
   while((i<= mid-1) && (j<=right))
   {
      if(arr[i] <= arr[j])
         temp[k++] = arr[i++];
      else
      {
         temp[k++] = arr[j++];

         invCount = invCount + (mid - i);
      }
   }

   while(i<=mid-1)
      temp[k++] = arr[i++];
   while(j<=right)
      temp[k++] = arr[j++];

   return invCount;
}

int _mergeSort( int arr[], int temp[], int left, int right ) {
   int mid, invCount = 0;
   if( right > left ) {
      mid=( left+right )/2;

      invCount += _mergeSort( arr, temp, left, mid );
      invCount += _mergeSort( arr, temp, mid + 1, right );

      invCount += _merge( arr, temp, left, mid+1, right );

   }
   return invCount;
}

int main() {
   int n, i;
   cin>>n;
   int a[n], temp[n];
   for( i=0; i<n; i++ )
      cin>>a[i];

   int ans = _mergeSort( a, temp, 0, n-1 );
   cout<<"Number of inversions are : "<<ans;
   return 0;
}
