#include <bits/stdc++.h>

using namespace std;
/*
   Time complexity O(logn)
*/

int main()
{
   int n,k;
   cin>>n>>k;

   vector<int>a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];

   int left=0, right=n-1, flag=0;

   while(left<=right)
   {
      int mid = (left+right)/2;
      if(a[mid] == k)
      {
         flag = mid;
         break;
      }
      if(a[mid] > k)
         right = mid - 1;
      if(a[mid] < k)
         left = mid + 1;
   }
   flag ? cout<<"Avaialble in index = "<<flag : cout<<"NO";
   return 0;
}
