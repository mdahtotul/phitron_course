#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int data;
   node *nxt;
};

class LinkedList {
 public:
   int sz;
   node *head;

   LinkedList() {
      sz=0;
      head=NULL;
   }

   // function to create new node
   node *CreateNewNode( int val ) {
      node *insertingNode = new node;
      insertingNode->data = val;
      insertingNode->nxt = NULL;
      return insertingNode;
   }
   //function to insert node at head
   void InsertAtHead( int val ) {
      sz++;
      node *newNode = CreateNewNode( val );
      if( head == NULL ) {
         head = newNode;
         return;
      }
      newNode->nxt = head;
      head = newNode;
   }
   //function to insert node in the end
   void InsertInTheEnd( int val ) {
      node *newNode = CreateNewNode( val );
      if( head == NULL ) {
         head = newNode;
         return;
      }
      node *a = head;
      int cur_idx = 0;
      while( cur_idx != sz-1 ) {
         a=a->nxt;
         cur_idx++;
      }
      a->nxt = newNode;
      sz++;
   }
   //function to remove node from head
   void RemoveFromHead() {
      if( head == NULL )
         return;

      sz--;
      node *a = head;
      head = a->nxt;
      delete a;
   }
   //function to remove node from last index
   void RemoveFromTail() {
      if( head == NULL )
         return;
      node *a = head;
      int cur_idx = 0;
      while( a != NULL ) {
         a=a->nxt;
         if( cur_idx == sz-1 ) {
            delete a;
            break;
         }
         cur_idx++;
      }
      sz--;
   }
   //function to print node
   void Travers() {
      node *a = head;
      int cur_idx = 0;
      //while ( a != NULL ) {
      while ( cur_idx < sz ) {
         cout<<a->data<<" ";
         a = a->nxt;
         cur_idx++;
      }
      cout<<"\n";
   }
   // linear search for linked list
   int searchLinkedList( int index ) {
      if( head == NULL )
         return -1;
      node *a = head;
      int cur_idx = 0;
      while( a != NULL ) {
         if( cur_idx == index ) {
            return a->data;
         }
         a = a->nxt;
         cur_idx++;
      }
      return -1;
   }

   void sortLinkedList() {
      if( head == NULL )
         return;
      node *a = head;

   }

   int getSize() {
      return sz;
   }

};

int main() {
   LinkedList l;

//   l.InsertAtHead( 5 );
//   l.InsertAtHead( 4 );
//   l.InsertAtHead( 3 );
//   l.InsertAtHead( 2 );
//   l.InsertAtHead( 1 );

   cout<<"Size -> "<<l.getSize()<<"\n";
   l.Travers();
//   l.RemoveFromHead();
//   l.RemoveFromTail();
//   cout<<"Linked list value = "<<l.searchLinkedList(2)<<"\n";
   l.InsertInTheEnd( 0 );
   cout<<"Size -> "<<l.getSize()<<"\n";
   l.Travers();

   return 0;
}
