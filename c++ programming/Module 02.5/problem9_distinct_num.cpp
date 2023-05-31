#include <bits/stdc++.h>

using namespace std;

int main()
{
   int i=0, cnt=0;
   long long int n;
   cin>>n;

   vector<int> a(n);
   for(i=0; i<n; i++)
      cin>>a[i];

   sort(a.begin(), a.end());

   for(i=1; i<n; i++)
   {
      if(a[i] != a[i-1])
         cnt++;
   }

   cout<<cnt+1;
   return 0;
}
