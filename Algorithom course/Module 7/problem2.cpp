#include <bits/stdc++.h>
using namespace std;

int calc_power(int ans, int n, int m) {
   if(m==0){
      return ans;
   }

   return calc_power(ans*n, n, m-1);
}

int main(){
   int n, m;
   cin>>n>>m;

   cout<<calc_power(1, n, m);
   return 0;
}
