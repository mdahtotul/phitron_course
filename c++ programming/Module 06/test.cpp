#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];

   for(int i=1; i<n; i++)
   {
      int l_idx = i;
      while(l_idx >= 1)
      {
         if(a[l_idx-1] > a[l_idx])
         {
            swap(a[l_idx-1], a[l_idx]);
            l_idx--;
         }
         else
            break;
      }
   }

   for(int i=0; i<n; i++)
      cout<<a[i]<<" ";

   return 0;
}
