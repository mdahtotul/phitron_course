#include <bits/stdc++.h>
using namespace std;

void _swap(int arr[], int i,int j)
{
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int _partition( int ar[], int l_idx,int h_idx ) {
   int pivot = ar[h_idx];
   int i = l_idx-1;

   for( int j=l_idx; j<h_idx; j++ ) {
      if( ar[j]>pivot ) {
         i++;
         _swap( ar, i, j );
      }
   }
   _swap( ar, i+1, h_idx );
   return i+1;
}

void quickSort( int arr[], int l_idx, int h_idx ) {
   if( l_idx<h_idx ) {
      int pi_idx = _partition( arr, l_idx, h_idx );

      quickSort( arr, l_idx, pi_idx-1 );
      quickSort( arr, pi_idx+1, h_idx );
   }
}

int main() {
   int n;
   cin>>n;
   int a[n];
   for( int i=0; i<n; i++ )
      cin>>a[i];

   quickSort( a, 0, n-1 );
   for(int i=0; i<n; i++)
      cout<<a[i]<<" ";

   cout<<"\n";
   return 0;
}
