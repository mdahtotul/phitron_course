#include <bits/stdc++.h>
using namespace std;

vector<int> freq(vector<int> a, int len)
{
   int maxx = a[0], i=0;
   for(i=0; i<len; i++)
   {
      if(maxx < a[i])
         maxx = a[i];
   }

   vector<int> freq_arr(maxx, 0);
   for(i=0; i<=maxx; i++)
      freq_arr[a[i]]++;

   return freq_arr;
}

int main()
{
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];

   vector<int> ans = freq(a, n);
   for(int i=0; i<=ans.size(); i++)
   {
      if(ans[i] > 0)
      {
         for(int j=0; j<ans[i]; j++)
            cout<<i<<" ";
      }
   }
   return 0;
}
