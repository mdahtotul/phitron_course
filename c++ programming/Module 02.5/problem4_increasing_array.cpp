#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int n, i, move=0;
   cin>>n;

   int a[n];
   for(i=0; i<n; i++)
      cin>>a[i];

   for(i=1; i<n; i++)
   {
      if(a[i]<a[i-1])
      {
         move += (a[i-1]-a[i]);
         a[i] = a[i-1];
      }
   }

   cout<<move;

   return 0;
}
