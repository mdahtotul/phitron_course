#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 50;
template <class T>
class Stack {
 public:
   T *a;
   int stk_sz;
   int arr_cap;

   Stack() {
      a = new T[1];
      stk_sz = 0;
      arr_cap = 0;
   }

   void increaseSize() {
      T *tmp;
      tmp = new T[arr_cap*2];
      for(int i=0; i<arr_cap; i++){
         tmp[i] = a[i];
      }
      swap(a, tmp);
      delete []tmp;
      arr_cap = arr_cap*2;
   }

   void decreaseSize() {
      T *tmp;
      tmp = new T[arr_cap/2];
      for(int i=0; i<arr_cap; i++)
         tmp[i] = a[i];

      swap(a, tmp);
      delete []tmp;
      arr_cap = arr_cap/2;
   }

   void pushEle( T val ) {
      if( stk_sz+1 > mx_sz ) {
         increaseSize();
      }

      stk_sz++;
      a[stk_sz-1] = val;
      if(stk_sz < arr_cap/2){
         decreaseSize();
      }
   }

   void popEle() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      a[stk_sz-1] = 0;
      stk_sz--;
      if(stk_sz < arr_cap/2){
         decreaseSize();
      }
   }

   int top() {
      if( stk_sz==0 ) {
         cout<<"Stack is empty\n";
         T a;
         return a;
      }
      if(stk_sz < arr_cap/2){
         decreaseSize();
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

