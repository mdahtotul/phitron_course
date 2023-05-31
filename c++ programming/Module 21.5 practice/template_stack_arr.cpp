#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 500;
template <class T>
class Stack {
 public:
   T a[mx_sz];
   int stk_sz;

   Stack() {
      stk_sz = 0;
   }

   void pushEle( T val ) {
      if( stk_sz+1 > mx_sz ) {
         cout<<"Stack is full!\n";
         return;
      }

      stk_sz++;
      a[stk_sz-1] = val;
   }

   void popEle() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      a[stk_sz-1] = 0;
      stk_sz--;
   }

   int top() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty\n";
         T a;
         return a;
      }
      return a[stk_sz-1];
   }

   void traverseStack() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      int i=0;
      while( i<stk_sz ) {
         cout<<a[i]<<" ";
         i++;
      }
      cout<<"\n";
   }
};

int main() {
   Stack <double> st;
   st.pushEle( 3.3 );
   st.pushEle( 5.4 );
   st.pushEle( 7.8 );
   st.traverseStack();

   Stack <char> st2;
   st2.pushEle( 'a' );
   st2.pushEle( 'd' );
   st2.pushEle( 'c' );
   st2.traverseStack();
   return 0;
}

