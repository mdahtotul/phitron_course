#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
 public:
   T data;
   node* nxt;
};

template<class T>
class SinglyLinkedList {
 public:
   node<T>* head;
   int sz;

   SinglyLinkedList() {
      head = NULL;
      sz = 0;
   }

   node<T>* CreateNewNode( T val ) {
      node<T>* new_node = new node<T>;
      new_node->data = val;
      new_node->nxt = NULL;
      return new_node;
   }

   void InsertAtHead( T val ) {
      sz++;
      node<T>* newNode = CreateNewNode( val );
      if( sz==0 ) {
         head = newNode;
         return;
      }

      newNode->nxt = head;
      head = newNode;
   }

   void RemoveFromHead() {
      if( sz==0 ) {
         cout<<"Stack is empty!\n";
         return;
      }
      sz--;
      node<T>* a = head;
      head = head->nxt;

      delete a;
   }

   void Traverse() {
      node<T>* a = head;
      while( a!=NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

template<class T>
class Stack {
 public:
   SinglyLinkedList<T> sl;

   Stack(){
   }

   void pushToStack( T val ) {
      sl.InsertAtHead( val );
   }

   void popFromStack() {
      sl.RemoveFromHead();
   }

   void traverseStack() {
      sl.Traverse();
   }

   T top(){
      if(sl.sz == 0)
      {
         cout<<"Stack is empty!\n";
         T a;
         return a;
      }
      return sl.head->data;
   }
};

int main() {
   Stack<int> st;

   st.pushToStack( 5 );
   st.pushToStack( 10 );
   cout<<"Top -> "<<st.top()<<"\n";
   st.pushToStack( 15 );

   st.traverseStack();

   return 0;
}
