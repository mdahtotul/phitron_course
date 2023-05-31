#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int data;
   node * nxt;
};

class LinkedList {
 public:
   int sz;
   node *head;
   LinkedList() {
      head = NULL;
      sz = 0;
   }

   node *CreateNewNode( int val ) {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      return newNode;
   }

   void InsertAtHead( int val ) {
      sz++;
      node *insertNode = CreateNewNode( val );
      if( head == NULL ) {
         head = insertNode;
         return;
      }
      insertNode->nxt = head;
      head = insertNode;
   }

   void Travers() {
      node *a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

int main() {
   LinkedList l;
   l.InsertAtHead( 5 );
   l.InsertAtHead( 4 );
   l.InsertAtHead( 3 );
   l.InsertAtHead( 2 );
   l.InsertAtHead( 1 );
   l.InsertAtHead( 0 );

   l.Travers();
   return 0;
}
