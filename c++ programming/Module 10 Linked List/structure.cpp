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
   // constructor
   LinkedList() {
      head = NULL;
   }

   // creates a new node with data = value and nxt = NULL
   node* CreateNewNode( int val ) {
      node* newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;

      return newNode;
   }
   void InsertAtHead( int value ) {
      node *nd = CreateNewNode( value );
      if( head == NULL ) {
         head = nd;
         return;
      }
      nd->nxt = head;
      head = nd;

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
};

int main() {

   LinkedList link;
   link.InsertAtHead( 10 ); //4th head
   link.InsertAtHead( 30 ); //3rd head
   link.InsertAtHead( 20 ); //2nd head
   link.InsertAtHead( 30 ); //1st head

   link.Traverse();
   cout<<"\n\nSearch distinct value ====>\n";
   cout<<"10 is found at index "<<link.SearchDistinctValue( 10 )<<"\n";
   cout<<"5 is found at index "<<link.SearchDistinctValue( 5 )<<"\n";
   cout<<"30 is found at index "<<link.SearchDistinctValue( 30 )<<"\n";

   cout<<"\n\nSearch all matched value ====>\n";
   link.SearchAllValue( 30 );
   return 0;
}
