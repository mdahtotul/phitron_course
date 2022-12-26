#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,i;
   cin>>n;
   int a[n];


   for(i=0; i<n; i++)
      cin>>a[i];

   int sum=0, multi=1;
   for(i=0; i<n; i++)
      sum += a[i];

   for(i=0; i<n; i++)
      multi *= a[i];

   cout<<"Sum = "<<sum<<endl;
   cout<<"Multi = "<<multi<<endl;
   return 0;
}
