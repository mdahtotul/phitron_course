#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int data;
   node * nxt;
   node * prv;
};

class DoublyLinkedList {
 public:
   node * head;
   int sz;

   DoublyLinkedList() {
      head = NULL;
      sz=0;
   }

   node *CreateNewNode( int val ) {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }

   void InsertAtHead( int val ) {
      sz++;
      node *nd = CreateNewNode( val );
      if( head == NULL ) {
         head = nd;
         return;
      }
      node *a = head;
      nd->nxt = a;
      a->prv = nd;
      head = nd;
   }

   void DeleteFromHead() {
      if ( head == NULL ) {
         cout<<"No node available\n";
         return;
      }
      node *a = head;
      node *b = head->nxt;
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
      node *a = head;
      while( a!=NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

class Stack {
 public:
   DoublyLinkedList dl;

   Stack() {


   }

   int top () {
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         return -1;
      }
      return dl.head->data;
   }

   void pushToStack( int val ) {
      dl.InsertAtHead( val );
   }

   void popFromStack() {
      cout<<"Size = "<<dl.getSize()<<"\n";
      if( dl.getSize() == 0 ) {
         cout<<"Stack is empty\n";
         return;
      }
      dl.DeleteFromHead();
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

   //cout<<"Size -> "<<dl.getSize()<<"\n";
   return 0;
}
