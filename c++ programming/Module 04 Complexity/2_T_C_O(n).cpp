#include <bits/stdc++.h>

using namespace std;

/*
Time complexity O(n);
Memory complexity O(n);
*/

int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];

   int maxx = a[0], minn = a[0], sum =0;

   for(int i=0; i<n; i++)
   {
      maxx = max(maxx, a[i]);
      minn = min(minn, a[i]);
      sum += a[i];
   }
   cout<<maxx<<"\n";
   cout<<minn<<"\n";
   cout<<sum<<"\n";
}
