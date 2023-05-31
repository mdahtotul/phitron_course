#include <bits/stdc++.h>
using namespace std;

/**
   0-----1
       /  \
      2----3

      2
   0 ---> 1
      4
   1 ---> 2
      8
   3 ---> 2
      7
   3 ---> 1
*/


int main(){

   int nodes = 4;
   vector<int>adj_list[nodes];

   // O(E)
   adj_list[0] = {1};
   adj_list[1] = {2};
   adj_list[2] = {};
   adj_list[3] = {1, 2};

   for(int i=0; i<nodes; i++) {
         cout<<i<<" -> ";
      for(int j=0; j<adj_list[i].size(); j++){
         cout<<adj_list[i][j]<<" ";
      }
      cout<<"\n";
   }

   return 0;
}
