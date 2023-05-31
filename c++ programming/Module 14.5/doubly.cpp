#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int data;
   node * prv;
   node * nxt;
};

class DoublyList {
 public:
   int sz;
   node *head;
   // constructor
   DoublyList() {
      head = NULL;
      sz=0;
   }
   // func to create new node O(1)
   node *CreateNode( int val ) {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }
   // func to insert node at head O(1)
   void InsertAtHead( int val ) {
      sz++;
      node *c_node= CreateNode( val );
      if( head == NULL ) {
         head = c_node;
         return;
      }
      node *a = head;
      c_node->nxt = a;
      a->prv = c_node;
      head = c_node;
   }
   // func to insert at any index O(n)
   void InsertAtAnyIndex( int idx, int val ) {
      if( idx < 0 || idx>sz )
         return;
      if( idx == 0 ) {
         InsertAtHead( val );
         return;
      }
      sz++;
      node *a = head;
      int i=0;
      while( i!=idx-1 ) {
         a=a->nxt;
         i++;
      }
      node *new_node= CreateNode( val );
      node *b = a;
      node *c = a->nxt;

      new_node->nxt = c;
      new_node->prv = b;
      b->nxt = new_node;
      c->prv = new_node;
   }
   // func to delete last element O(1)
   void DeleteFromTail() {
      if( head == NULL )
         return;

      sz--;
      node *a = head;
      int i=0;
      while( i != sz ) {
         a=a->nxt;
         i++;
      }
      node *b = a->prv;
      b->nxt = NULL;
      delete a;
   }
   // func to delete form any index O(n)
   void DeleteFormAnyIndex( int idx ) {
      if( idx<0 || idx>=sz ) {
         cout<<"Invalid index\n";
         return;
      }
      if( head==NULL )
         return;
      node *a = head;
      int i=0;
      while( i!=idx ) {
         a=a->nxt;
         i++;
      }
      node *b = a->prv;
      node *c = a->nxt;

      if( b != NULL )
         b->nxt = c;
      if( c != NULL )
         c->prv = b;
      delete a;
      if( idx == 0 )
         head = c;
      sz--;
   }
   // func to delete using value O(n)
   void DeleteByValue( int val ) {
      if( head==NULL )
         return;
      node *a = head;
      int i=0;
      while( a!=NULL ) {
         if( a->data == val )
            break;
         a=a->nxt;
         i++;
      }
      node *b = a->prv;
      node *c = a->nxt;

      if( b != NULL )
         b->nxt = c;
      if( c != NULL )
         c->prv = b;
      delete a;
      sz--;
   }
   // func to search value by index O(n)
   int findValueByIdx( int idx ) {
      if( head == NULL ) {
         cout<<"Linked list not found\n";
         return -1;
      }
      if( idx<0 || idx>=sz ) {
         cout<<"Invalid index\n";
         return -1;
      }
      node *a = head;
      int i=0;
      while( a!= NULL ) {
         if( i == idx )
            return a->data;
         a=a->nxt;
         i++;
      }
      cout<<"Value not found!";
      return -1;
   }
   // func to reverse doubly linked list O(n)
   void ReverseList() {
      if( head==NULL )
         return;

      node *a = head;
      int i=0;
      while( i != sz-1 ) {
         a=a->nxt;
         i++;
      }
      node *b = head;
      while( b!=NULL ) {
         swap( b->nxt, b->prv );
         b = b->prv;
      }
      head=a;
   }
   // func to print all nodes O(n)
   void Traverse() {
      node *a = head;
      while( a!=NULL ) {
         cout<<a->data<<" ";
         a=a->nxt;
      }
      cout<<"\n";
   }
   // get size O(1)
   int getSize() {
      return sz;
   }
};

int main() {
   DoublyList dl;
   dl.InsertAtHead( 7 );
   dl.InsertAtHead( 6 );
   dl.InsertAtHead( 5 );
   dl.InsertAtHead( 4 );
   dl.InsertAtHead( 3 );
   dl.InsertAtHead( 2 );
   dl.InsertAtHead( 1 );
   //dl.InsertAtHead( 0 );

   cout<<"Doubly linked list size -> "<<dl.getSize()<<"\n";
   dl.Traverse();

   //dl.DeleteFromTail();
   //cout<<"Searched index value = "<<dl.findValueByIdx( 2 )<<"\n";
   //dl.ReverseList();
   //dl.InsertAtAnyIndex(1, 0);
   dl.DeleteByValue( 4 );
   cout<<"Doubly linked list size -> "<<dl.getSize()<<"\n";
   dl.Traverse();
   return 0;
}
