#include <bits/stdc++.h>
using namespace std;
const int mx_sz = 500;

class Stack {
 public:
   int a[mx_sz];
   int stk_sz;

   Stack() {
      stk_sz= 0;
   }
   // add an element in stack O(1)
   void pushToStack( int val ) {
      if( stk_sz+1 > mx_sz ) {
         cout<<"Stack is full!\n";
         return;
      }
      stk_sz++;
      a[stk_sz-1] = val;
   }
   // remove top most element from the stack O(1)
   void popFromStack() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty!\n";
         return;
      }
      a[stk_sz-1] = 0;
      stk_sz--;
   }

   // return the top element from the stack
   int top() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty!\n";
         return -1;
      }

      return a[stk_sz-1];
   }
};

int main() {
   Stack st;
   st.pushToStack( 3 );
   cout<<st.top()<<"\n";
   st.pushToStack( 4 );
   cout<<st.top()<<"\n";
   st.pushToStack( 5 );
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
}

/**
   @stack should be implement using dynamic array
*/
