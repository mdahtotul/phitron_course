#include <bits/stdc++.h>
using namespace std;

int delete_elements(int a[], int start_pos, int end_pos, int n)
{
   int newIdx = 0;
   for(int i=0; i<n; i++)
   {
      if(i>=start_pos && i<=end_pos)
         continue;
      else
      {
         a[newIdx] = a[i];
         newIdx++;
      }
   }
   return newIdx;
}

int main()
{
   int n, a, b;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++)
      cin>>arr[i];

   cin>>a>>b;

   int ans = delete_elements(arr, a-1, b-1, n);
   for(int i=0; i<ans; i++)
      cout<<arr[i]<<" ";

   return 0;
}
/*
6
1 4 6 2 8 7
2 4
*/
