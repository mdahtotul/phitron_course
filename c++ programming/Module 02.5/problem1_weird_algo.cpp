#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   long long int n;
   cin>>n;


   while(n>0){
      if(n==1)
      {
         cout<<n;
         break;
      }
      if(n%2==0)
      {
         cout<<n<<" ";
         n/=2;
      }
      else
      {
         cout<<n<<" ";
         n = (n*3)+1;
      }
   }
   return 0;
}
