#include <bits/stdc++.h>
using namespace std;

template <class T>
class node {
 public:
   T data;
   node * nxt;
};

template <class T>
class SinglyList {
 public:
   node<T> *head;
   int sz;

   SinglyList() {
      head = NULL;
      sz=0;
   }

   node<T> *CreateNewNode( T val ) {
      node<T> *newNode = new node<T>;
      newNode->data = val;
      newNode->nxt = NULL;
      return newNode;
   }

   void InsertAtHead( T val ) {
      sz++;
      node<T> *nd = CreateNewNode( val );
      if( head == NULL ) {
         head = nd;
         return;
      }
      node<T> *a = head;
      nd->nxt = a;
      head = nd;
   }

   void DeleteFromHead() {
      if( head == NULL ) {
         cout<<"List is already empty\n";
         return;
      }
      node<T> *a = head;
      node<T> *b = head->nxt;
      delete a;
      head = b;
      sz--;
   }

   int getSize() {
      return sz;
   }

   void Traverse() {
      node<T> *a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a=a->nxt;
      }
      cout<<"\n";
   }
};

template <class T>
class Stack {
 public:
   SinglyList<T> sl;

   Stack() {}

   void pushEle( T val ) {
      sl.InsertAtHead( val );
   }

   void popEle(){
      sl.DeleteFromHead();
   }

   void stack_sz(){
      return sl.getSize();
   }

   void traverseStack() {
      sl.Traverse();
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

