#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s;
   cin>>s;

   int i = 0;
   while(s[i] != '\0')
   {
      if(s[i] == 'z')
      {
         cout<<'a';
         i++;
         continue;
      }
      if(i%2==0)
      {
         char c = s[i] + 1;
         cout<<c;
      }
      else
         cout<<s[i];

      i++;
   }

   return 0;
}
