#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int n, i;
   cin>>n;
   int a[n+1];
   for(i=1; i<=n; i++)
      a[i] = 0;

   for(i=1; i<=n-1; i++)
   {
      int idx;
      cin>>idx;
      a[idx] = 1;
   }

   for(i=1; i<=n; i++)
   {
      if(a[i]==0)
      {
         cout<<i;
         break;
      }
   }
   return 0;
}
