#include <bits/stdc++.h>
using namespace std;

int main(){
   set<int> st;

   st.insert(5);
   st.insert(3);
   st.insert(4);
   st.insert(7);
   st.insert(3);
   st.insert(4);

   for(auto i: st)
      cout<<i<<" ";
   cout<<"\n";

   cout<<"Set size : "<<st.size()<<"\n";

   for(auto it=st.begin(); it!= st.end(); it++)
      cout<<*it<<" ";
   cout<<"\n";

   st.erase(4);
   for(auto i: st)
      cout<<i<<" ";
   cout<<"\n";

   if(st.find(7) != st.end())
      cout<<"7 found\n";
   else
      cout<<"7 not found\n";


   return 0;
}

/**Time complexity
   @Insert O(logn)
   @Erase O(logn)
   @Find O(logn)
   @Print O(n)
*/
