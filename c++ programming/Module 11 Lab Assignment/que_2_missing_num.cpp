#include <bits/stdc++.h>
using namespace std;

void missing_num(int a[], int n)
{
   int maxx=a[1], i=0;
   for(i=1; i<=n; i++)
   {
      if(a[i] > maxx)
         maxx = a[i];
   }

   int freq[maxx];
   for(i=1; i<=maxx; i++)
      freq[i] = 0;

   for(i=1; i<=maxx; i++)
      freq[a[i]] = 1;

   for(i=1; i<=maxx; i++)
   {
      if(freq[i] == 0)
         cout<<i;
   }
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for( int i=1; i<=n-1; i++ )
      cin>>a[i];

   missing_num(a, n-1);
   return 0;
}
