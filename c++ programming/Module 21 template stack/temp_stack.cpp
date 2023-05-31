#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 500;

template <class T>
class Stack {
 public:
   T *a;
   int stk_sz;
   int arr_cap;

   Stack() {
      a = new T[1];
      arr_cap = 1;
      stk_sz= 0;
   }
   // makes the array cap multiplied by 2;
   void increaseSize() {
      T *tmp;
      tmp = new T[arr_cap*2];
      for(int i=0; i<arr_cap; i++)
         tmp[i] = a[i];
      swap(a, tmp);
      delete []tmp;
      arr_cap = arr_cap * 2;
   }
   // add an element in stack O(1)
   void pushToStack( T val ) {
      if( stk_sz+1 > mx_sz ) {
         increaseSize();
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
      stk_sz--;
   }

   // return the top element from the stack
   T top() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty!\n";
         T a;
         return a;
      }
      return a[stk_sz-1];
   }
};

int main() {
   Stack <double> st;
   st.pushToStack(3.5);
   st.pushToStack(3.9);
   st.pushToStack(3.7);
   st.pushToStack(3.3);
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();
   cout<<st.top()<<"\n";
   st.popFromStack();

   return 0;
}

/**
   @stack should be implement using dynamic array
*/
