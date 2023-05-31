
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
   int sz;
   // constructor
   LinkedList() {
      head = NULL;
      sz = 0;
   }

   // creates a new node with data = value and nxt = NULL
   node* CreateNewNode( int val ) {
      node* newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;

      return newNode;
   }
   void InsertAtHead( int value ) {
      sz++;
      node *nd = CreateNewNode( value );
      if( head == NULL ) {
         head = nd;
         return;
      }
      nd->nxt = head;
      head = nd;
   }

   void DeleteAtHead() {
      if( head == NULL ) return;
      sz--;
      node *a = head;
      head = a->nxt;
      delete a;
   }

   void InsertAtAnIndex( int idx, int val ) {
      if( idx<0 || idx>sz ) {
         return;
      }
      if( idx == 0 ) {
         InsertAtHead( val );
         return;
      }
      sz++;
      node *a = head;
      int cur_idx = 0;
      while( cur_idx != idx-1 ) {
         a = a->nxt;
         cur_idx++;
      }
      node *newNode = CreateNewNode( val );
      newNode->nxt = a->nxt;
      a->nxt = newNode;
   }

   void DeleteAtAnyIndex( int idx ) {
      if( idx < 0 || idx >= sz ) return;
      if( idx == 0 ) {
         DeleteAtHead();
         return;
      }
      sz--;
      node *a = head;
      int cur_idx = 0;
      while( cur_idx != idx-1 ) {
         a = a->nxt;
         cur_idx++;
      }
      node *b = a->nxt;
      a->nxt = b->nxt;
      delete b;
   }

   void Traverse() {
      node* a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
   int SearchDistinctValue( int val ) {
      node* a = head;
      int idx = 0;
      while( a != NULL ) {
         if( a->data == val )
            return idx;

         a = a->nxt;
         idx++;
      }
      return -1;

   }
   void SearchAllValue( int val ) {
      node* a = head;
      int idx = 0;
      while( a != NULL ) {
         if( a->data == val )
            cout<<"Value is found at index "<<idx<<"\n";

         a = a->nxt;
         idx++;
      }
   }

   int getSize() {
      return sz;
   }
};

int main() {

   LinkedList link;
   link.InsertAtHead( 10 ); //4th head
   link.InsertAtHead( 30 ); //3rd head
   link.InsertAtHead( 20 ); //2nd head
   link.InsertAtHead( 30 ); //1st head

   cout<<"Size -> "<<link.getSize()<<"\n";
   link.Traverse();
   //link.DeleteAtHead();
   link.DeleteAtAnyIndex( 1 );
   link.Traverse();
   cout<<"Size -> "<<link.getSize()<<"\n";

   cout<<"\n\nSearch distinct value ====>\n";
   cout<<"10 is found at index "<<link.SearchDistinctValue( 10 )<<"\n";
   cout<<"5 is found at index "<<link.SearchDistinctValue( 5 )<<"\n";
   cout<<"30 is found at index "<<link.SearchDistinctValue( 30 )<<"\n";

   cout<<"\n\nSearch all matched value ====>\n";
   link.SearchAllValue( 30 );
   return 0;
}
