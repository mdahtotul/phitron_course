#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
 public:
   T data;
   node *nxt;

};

template<class T>
class Queue {
 public:
   node<T>* head;
   node<T>* tail;
   int sz;

   Queue() {
      head = NULL;
      tail = NULL;
      sz = 0;
   }

   node<T>* CreateNewNode ( T val ) {
      node<T>* n_node = new node<T>;
      n_node->data = val;
      n_node->nxt = NULL;
      return n_node;
   }

   void enqueue( T val ) {
      node<T>* newNode = CreateNewNode( val );
      sz++;
      if( head == NULL ) {
         head = newNode;
         tail = newNode;
         return;
      }
      tail->nxt = newNode; // giving newNode address to the tail nxt null pointer
      tail = newNode; // latest created node will always tail
   }

   void dequeue() {
      if( head == NULL ) {
         cout<<"Queue is empty\n";
         return ;
      }
      if( sz==1 ) {
         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }

      sz--;
      node<T>* a = head;
      head = head->nxt;
      delete a;
   }

   T front_que() {
      if( sz==0 ) {
         cout<<"Queue is empty\n";
         T a;
         return a;
      }

      return head->data;
   }

   int getSize() {
      return sz;
   }

   void Traverse() {
      if( sz==0 ) {
         cout<<"Queue is empty\n";
         return;
      }

      node<T> *a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};


int main() {
   Queue <int> q;
   q.enqueue( 5 );
   q.enqueue( 10 );
   q.enqueue( 15 );

   cout<<"Queue size -> "<<q.getSize()<<"\n";

   cout<<q.front_que()<<"\n";
   q.dequeue();

   cout<<q.front_que()<<"\n";
   q.dequeue();

   cout<<q.front_que()<<"\n";
   q.dequeue();

   cout<<"Queue size -> "<<q.getSize()<<"\n";
   return 0;
}
