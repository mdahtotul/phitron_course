#include <bits/stdc++.h>
using namespace std;

void _swap(int arr[], int i, int j)
{
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int _partition( int arr[], int left, int right ) {
   int pivot = arr[right];
   int i=left-1;

   for( int j=left; j<right; j++ ) {
      if( arr[j]<pivot ) {
         i++;
         _swap( arr, i, j );
      }
   }
   _swap(arr, i+1, right);
   return i+1;
}

void quickSort( int arr[], int left, int right ) {
   if( left<right ) {
      int pivot = _partition( arr, left, right );

      quickSort( arr, left, pivot-1 );
      quickSort( arr, pivot+1, right );
   }
}

int main() {
   int arr[] = {5,8,7,6,3};
   int size = sizeof(arr) / sizeof(arr[0]);
   quickSort(arr, 0, size-1);
   for(int i=0; i<5; i++)
      cout<<arr[i]<<" ";

   cout<<"\n";
   return 0;
}
