#include <bits/stdc++.h>
using namespace std;

int main() {
   map<string, int> mp;
   mp["goru"] = 1;
   mp["chagol"] = 2;
   mp["vera"] = 3;

   cout<<mp["goru"]<<"\n";

   //print the map

   for(auto it: mp)
      cout<<"Key: "<<it.first <<", Value: "<<it.second<<"\n";

   return 0;
}
