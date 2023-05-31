#include <bits/stdc++.h>

using namespace std;

int main()
{
   int L, R;
   cin>>L;
   cin>>R;

   string S;
   cin>>S;

   int i=0;
   while(S[i]!='\0')
   {
      if(i>=L-1 && i<=R-1)
      {
         for(int j=R-1; j>=L-1; j--)
            cout<<S[j];

         i=R-1;
      }
      else
         cout<<S[i];

      i++;
   }
   return 0;
}
