#include <bits/stdc++.h>

using namespace std;

int factorial(int fact, int n)
{
   if(n>1)
   {
      fact = fact * n;
      return factorial(fact, n-1);
   }
   return fact;
}

int main()
{
   string s;
   cin>>s;

   int i=0;
   int a[27];
   for(i=0; i<=26; i++)
      a[i]=0;

   int j=0;
   while(s[j]!='\0')
   {
      a[s[j]-96]++;
      j++;
   }
   int total_factor = factorial(1, s.size());
   int div_factor = 1;
   for(i=1; i<=26; i++)
   {

      if(a[i]>0)
         div_factor = div_factor * factorial(1,a[i]);
   }

   cout<<total_factor/div_factor;
   return 0;
}
