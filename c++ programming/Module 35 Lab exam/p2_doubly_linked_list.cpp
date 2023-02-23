#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
   int value;
   Node* nxt;
   Node* prv;
};

class LinkedList {
 public:
   Node* head;
   Node* tail;
   int sz;

   LinkedList() {
      head = NULL;
      tail = NULL;
      sz=0;
   }

   Node* CreateNode ( int val ) {
      Node* newNode = new Node;
      newNode->value = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }

   void insertHead( int value ) {
      Node* new_node = CreateNode( value );
      if( head == NULL ) {
         head = new_node;
         tail = new_node;
         return;
      }

      new_node->nxt = head;
      head->prv = new_node;
      head = new_node;
      sz++;
   }
   void insertTail( int value ) {
      Node* new_node = CreateNode( value );
      if( head == NULL ) {
         head = new_node;
         tail = new_node;
         return;
      }

      new_node->prv = tail;
      tail->nxt = new_node;
      tail = new_node;
      sz++;
   }
   void insertMid( int value ) {
      Node* new_node = CreateNode( value );
      if( head == NULL ) {
         head = new_node;
         tail = new_node;
         return;
      }
      Node* a = head;
      int i=0;
      while( i != ( sz-1 )/2 ) {
         a= a->nxt;
         i++;
      }
      Node* b = a->nxt;
      a->nxt = new_node;
      new_node->prv = a;
      if( b != NULL ) {
         new_node->nxt = b;
         b->prv = new_node;
      }
      sz++;
   }
   void print() {
      if( head == NULL ) {
         cout<<"Doubly linked list empty!\n";
         return;
      }

      Node* a = head;
      while( a!=NULL ) {
         cout<<a->value<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }

   void Merge( LinkedList a ) {
      if(a.sz == 0) {
         cout<<"Doubly linked list empty!\n";
         return;
      }
      Node* b = a.head;
      while(b != NULL){
         insertTail(b->value);
         b = b->nxt;
      }
   }
};
int main() {
   LinkedList a;
   LinkedList b;

   a.insertHead( 1 );
   a.insertTail( 5 );
   a.insertMid( 3 );
   a.insertHead( 0 );
   a.insertTail( 10 );
   a.print(); // prints  0 1 3 5 10

   b.insertHead( 10 );
   b.insertTail( 50 );
   b.insertMid( 30 );
   b.insertHead( 9 );
   b.insertTail( 100 );
   b.print(); // prints  9 10 30 50 100

   a.Merge( b );
   a.print(); // prints  0 1 3 5 10 9 10 30 50 100
   b.print(); // prints  9 10 30 50 100
}
