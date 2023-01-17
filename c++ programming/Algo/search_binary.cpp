#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, k;
   cout<<"Array size : ";
   cin>>n;
   cout<<"Searching number : ";
   cin>>k;

   vector<int>a(n);

   for(int i=0; i<n; i++)
      cin>>a[i];

   int left=0, right=n-1, flag=-1;
   for(int i=0; i<n; i++)
      cout<<a[i]<<" ";

   cout<<"\n";
   while(left<=right)
   {
      int mid = (left+right)/2;
      if(a[mid] == k)
      {
         flag = mid;
         cout<<"Value "<<k<<" is available at index "<<mid<<"\n";
         break;
      }
      if(a[mid]>k)
         right = mid - 1;
      if(a[mid]<k)
         left = mid + 1;
   }
}
