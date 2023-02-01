#include <bits/stdc++.h>
using namespace std;

int main(){
   stack<int> st;
   st.push(10);
   st.push(20);
   st.push(30);

   cout<<"Stack size = "<<st.size()<<"\n";
   cout<<st.top()<<"\n";

   st.pop();
   cout<<st.top()<<"\n";
   st.pop();
   cout<<st.top()<<"\n";   st.pop();
   cout<<"Stack size = "<<st.size()<<"\n";
   return 0;
}
