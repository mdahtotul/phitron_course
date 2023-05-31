#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int data;
   node * nxt;
};

class LinkedList {
 public:
   node * head;
   int len;
   // constructor
   LinkedList() {
      head = NULL;
      len = 0;
   }

   node* CreateNewNode ( int val ) {
      node* newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      len++;
      return newNode;
   }

   void InsertAtHead( int value ) {
      node* nd = CreateNewNode( value );

      if( head == NULL ) {
         head = nd;
         return;
      }
      nd->nxt = head;
      head = nd;
   }

   int getSize() {
      return len;
   }

   int getValue( int idx ) {
      node* a = head;
      int cnt = 0;
      if( idx>= len ) return -1;
      while( a != NULL ) {
         if( cnt == idx )
            return ( a->data );
         cnt++;
         a = a->nxt;
      }

      assert( 0 );
   }

   // recursive function to print data
   void ReversePrint( class node* p ) {
      if( p == NULL )
         return;

      ReversePrint( p->nxt );
      cout<<p->data<<" ";
   }

   void printReverse() {
      node* a = head;
      ReversePrint( a );
      cout<<"\n";
   }

   void Traverse() {
      node* nd = head;
      while( nd != NULL ) {
         cout<<nd->data<<" ";
         nd = nd->nxt;
      }
      cout<<"\n";
   }

   void swapFirst() {
      if( len < 2 ) return;
      node* temp = head->nxt;
      head->nxt = temp->nxt;
      temp->nxt = head;
      head = temp;

   }
};

int main() {
   LinkedList l;
   cout<<l.getSize()<<"\n";
   l.InsertAtHead( 5 );
   cout<<l.getSize()<<"\n";
   l.InsertAtHead( 6 );
   l.InsertAtHead( 30 );
   cout<<l.getSize()<<"\n";
   l.InsertAtHead( 20 );
   l.InsertAtHead( 30 );

   cout<<l.getValue( 2 )<<"\n";

   cout<<l.getValue( 6 )<<"\n";

   l.printReverse();
   l.Traverse();
   l.swapFirst();
   l.Traverse();
   l.printReverse();
   return 0;
}
