#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   string s;
   cin>>s;

   long long int i, flag=0, maxx=0;
   char lc;
   for(i=0; i<s.size(); i++)
   {
      if(s[i]!= lc)
      {
         maxx = max(flag, maxx);
         flag=1;
      }
      else
      {
         flag++;
      }
      lc = s[i];
   }

   maxx = max(flag, maxx);
   cout<<maxx;
   return 0;
}
