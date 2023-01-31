#include <bits/stdc++.h>
using namespace std;

int _partition( int arr[], int low, int high ) {
   int pivot = arr[high];
   int i = low-1;

   for( int j=low; j<high; j++ ) {
      if( arr[j] > pivot ) {
         i++;
         swap( arr[i], arr[j] );
      }
   }
   // putting pivot item in its right place
   swap( arr[i+1], arr[high] );
   return i+1;
}

int partition_rand( int arr[], int low, int high ) {
   // Using current time as seed for random generator
   srand( time( NULL ) );
   // generating random pivot index
   int rand_pivot = low + rand()%( high-low );
   // swapping pivot number with last index
   swap( arr[rand_pivot], arr[high] );
   // calling partition function to do the rest
   return _partition( arr, low, high );
}

void quickSort( int arr[], int low, int high ) {
   if( low<high ) {
      int piv = partition_rand( arr, low, high );

      quickSort( arr, low, piv-1 );
      quickSort( arr, piv+1, high );
   }
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for( int i=0; i<n; i++ )
      cin>>arr[i];

   quickSort( arr, 0, n-1 );
   for( int i=0; i<n; i++ )
      cout<<arr[i]<<" ";

   return 0;
}
