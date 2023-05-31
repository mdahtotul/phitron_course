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
   int sz;
   node * head;

   DoublyLinkedList () {
      sz = 0;
      head = NULL;
   }
   // function to create a new node and return the node data
   node *CreateNewNode( int val ) {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }

   void InsertAtHead( int val ) {
      sz++;
      node *createdNode = CreateNewNode( val );
      if( head == NULL ) {
         head = createdNode;
         return;
      }
      node *a = head;
      createdNode->nxt = a;
      a->prv = createdNode;
      head = createdNode;
   }

   void InsertAtAnyIndex( int idx, int val ) {
      if( idx<0 || idx>sz ) {
         cout<<"Given index should be greater than -1 and smaller than "<<sz<<"\n";
         return;
      }

      if( idx == 0 ) {
         InsertAtHead( val );
         return;
      }
      node *a = head;
      int cur_idx = 0;
      while( cur_idx != idx-1 ) {
         a=a->nxt;
         cur_idx++;
      }
      /* Initially, A->nxt = nodeB and prvB = nodeA
         [prvA||dataA||nxtA] [prvB||dataB||nxtB]
         After inserting new node, A->nxt = newNode and newNode->prv = nodeA && newNode->nxt =nodeB and B->prv=newNode
         [prvA||dataA||nxtA] [prvNew||dataNew||nxtNew] [prvB||dataB||nxtB]

      */
      node *newNode = CreateNewNode( val );
      node *b = a->nxt;

      newNode->nxt = b;
      newNode->prv = a;
      a->nxt = newNode;
      b->prv = newNode;
      sz++;
   }

   void DeleteNode( int idx ) {
      if( idx >= sz ) {
         cout<<"Index doesn't exist"<<"\n";
         return;
      }
      node *a = head;
      int cur_idx =0 ;
      while( cur_idx != idx ) {
         a = a->nxt;
         cur_idx++;
      }

      node *b = a->prv;
      node *c = a->nxt;

      if( b!=NULL )
         b->nxt = c;

      if( c!=NULL )
         c->prv = b;

      delete a;

      if( idx==0 )
         head=c;

      sz--;
   }

   int getSize() {
      return sz;
   }

   void ReverseLinkedList() {
      if(head==NULL)
         return;

      node *a = head;
      int i=0;
      while( i!= sz-1 ) {
         a=a->nxt;
         i++;
      }
      node *b = head;
      while( b != NULL ) {
         swap( b->nxt, b->prv );
         b=b->prv;
      }

      head = a;
   }

   void Traverse() {
      node *a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }

};

int main() {

   DoublyLinkedList dl;
   dl.InsertAtHead( 10 );
   dl.InsertAtHead( 5 );
   dl.InsertAtHead( 1 );

   dl.Traverse();
   cout<<"Linked list size = "<<dl.getSize()<<"\n";

   dl.InsertAtAnyIndex( 2, 100 );
   dl.Traverse();
   cout<<"Linked list size = "<<dl.getSize()<<"\n";

   dl.DeleteNode( 2 );
   dl.Traverse();
   cout<<"Linked list size = "<<dl.getSize()<<"\n";

   dl.ReverseLinkedList();
   dl.Traverse();
   cout<<"Linked list size = "<<dl.getSize()<<"\n";
   return 0;
}
