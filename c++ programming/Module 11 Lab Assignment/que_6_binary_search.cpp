#include <bits/stdc++.h>
using namespace std;

int bin_src(int a[], int left, int n, int k)
{
   int f_idx = -1, l_idx = -1;
   int right;
   right = n-1;
   while(left<=right)
   {
      int mid = (left+right)/2;
      if(a[mid] == k)
      {
         f_idx = mid;
         left = mid+1;
      }
      if(a[mid] > k)
         right = mid-1;
      if(a[mid] < k)
         left = mid+1;
   }

   left=0, right = n-1;
   while(left<=right)
   {
      int mid = (left+right)/2;
      if(a[mid] == k)
      {
         l_idx = mid;
         right = mid-1;
      }
      if(a[mid] > k)
         right = mid-1;
      if(a[mid] < k)
         left = mid+1;
   }

   if(f_idx - l_idx > 0)
      return 1;
   else
      return 0;
}

int main()
{
   int n, k;
   cin>>n;
   int a[n];
   for(int i=0; i<n; i++)
      cin>>a[i];
   cin>>k;

   int ans = bin_src(a, 0, n, k);
   ans ? cout<<"YES "<<ans : cout<<"NO";
   return 0;
}

/*
Sample 01
7
1 6 6 6 8 9 17
6
Sample 02
10
1 2 3 4 5 6 7 8 9 10
5
*/
