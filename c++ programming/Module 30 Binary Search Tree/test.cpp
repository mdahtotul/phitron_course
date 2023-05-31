#include <bits/stdc++.h>
using namespace std;


int main () {
   int n = 10;
   for( int i = 1 ; i <= n/2 ; i++ ) {
      for( int j = 1 ; j <= n ; j = j + i ) {
         cout<<i<<" "<<j<<"\n";
      }
   }
   return 0;
}
