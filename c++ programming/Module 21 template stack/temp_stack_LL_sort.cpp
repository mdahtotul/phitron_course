#include <bits/stdc++.h>
using namespace std;

template <class T>
class node {
 public:
   T data;
   node * nxt;
   node * prv;
};

template <class T>
class DoublyLinkedList {
 public:
   node<T> * head;
   int sz;

   DoublyLinkedList() {
      head = NULL;
      sz=0;
   }

   node<T> *CreateNewNode( T val ) {
      node<T> *newNode = new node<T>;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
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
      a->prv = nd;
      head = nd;
   }

   void DeleteFromHead() {
      if ( head == NULL ) {
         cout<<"No node available\n";
         return;
      }
      node<T> *a = head;
      node<T> *b = head->nxt;
      delete a;
      if( b!=NULL ) {
         b->prv = NULL;
      }
      head = b;
      sz--;
   }

   int getSize() {
      return sz;
   }

   void Traverse() {
      node<T> *a = head;
      while( a!=NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

template <class T>
class Stack {
 public:
   DoublyLinkedList<T> dl;

   Stack() {


   }

   T top () {
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         T a;
         return a;
      }
      return dl.head->data;
   }

   void pushToStack( T val ) {
      dl.InsertAtHead( val );
   }

   void popFromStack() {
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      dl.DeleteFromHead();
   }

   void showStackdata() {
      dl.Traverse();
   }

   int stack_size() {
      return dl.getSize();
   }
};


int main() {
   Stack <int> st;
   st.pushToStack( 5 );
   st.pushToStack( 2 );
   st.pushToStack( 7 );
   st.pushToStack( 8 );
   st.pushToStack( 3 );

   st.showStackdata();

   Stack <int> tmp;

   while( st.stack_size() > 0 ) {
      int t = st.top();
      st.popFromStack();
      while( tmp.stack_size() > 0 ) {
         if( tmp.top() < t )
            break;
         st.pushToStack( tmp.top() );
         tmp.popFromStack();
      }
      tmp.pushToStack( t );
   }

   swap( st, tmp );

   st.showStackdata();

   return 0;
}
