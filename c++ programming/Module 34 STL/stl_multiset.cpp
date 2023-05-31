
#include <bits/stdc++.h>
using namespace std;

int main(){
   multiset<int> mt;

   mt.insert(5);
   mt.insert(7);
   mt.insert(4);
   mt.insert(3);
   mt.insert(4);
   mt.insert(7);

   cout<<"Printing multiset \n";
   for(auto it:mt)
      cout<<it<<" ";
   cout<<"\n";

   cout<<"Size of multiset : " <<mt.size()<<"\n";

   // erase all occurrence
   mt.erase(4);
   cout<<"Printing multiset \n";
   for(auto it:mt)
      cout<<it<<" ";
   cout<<"\n";

   cout<<"Size of multiset : " <<mt.size()<<"\n";

   // erase single occurrence
   mt.erase(mt.find(7));
   cout<<"Printing multiset \n";
   for(auto it:mt)
      cout<<it<<" ";
   cout<<"\n";

   cout<<"Size of multiset : " <<mt.size()<<"\n";

   if(mt.find(5) != mt.end())
      cout<<"5 found\n";
   else
      cout<<"5 not found\n";

   return 0;
}

/**Time complexity
   @Insert O(logn)
   @Erase O(logn)
   @Find O(logn)
   @Print O(n)
   @size O(1)
*/

