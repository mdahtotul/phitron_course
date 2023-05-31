#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];

   int m;
   cin>>m;
   vector<int>b(m);
   for(int i=0; i<m; i++)
      cin>>b[i];

   for(int x=0; x<n; x++)
   {
      for(int y=0; y<m; y++)
      {
         if(a[x] == b[y])
            cout<<a[x]<<" ";
      }
   }
   return 0;
}
