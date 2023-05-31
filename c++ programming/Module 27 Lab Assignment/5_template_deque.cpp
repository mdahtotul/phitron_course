#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
 public:
   T data;
   node* nxt;
   node* prv;
};

template<class T>
class Deque {
 public:
   node<T>* head;
   node<T>* tail;
   int sz;

   Deque() {
      head = NULL;
      tail = NULL;
      sz = 0;
   }

   node<T>* CreateNewNode ( T val ) {
      node<T>* new_node = new node<T>;
      new_node->data = val;
      new_node->nxt = NULL;
      new_node->prv = NULL;
      return new_node;
   }

   void push_front( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz == 0 ) {
         head = newNode;
         tail = newNode;
         sz++;
         return;
      }

      newNode->nxt = head;
      head->prv = newNode;
      head = newNode;
      sz++;
   }
   void push_back( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz == 0 ) {
         head = newNode;
         tail = newNode;
         sz++;
         return;
      }

      newNode->prv= tail;
      tail->nxt = newNode;
      tail = newNode;
      sz++;
   }

   void pop_front() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         return ;
      }

      if( sz == 1 ) {
         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }
      node<T>* a = head;
      head = head->nxt;
      head->prv = NULL;
      delete a;
      sz--;
   }
   void pop_back() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         return ;
      }

      if( sz == 1 ) {
         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }
      node<T>* a = tail;
      tail = tail->prv;
      tail->nxt= NULL;
      delete a;
      sz--;
   }

   int front() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return head->data;
   }

   int back() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return tail->data;
   }
   void Traverse() {
      node<T>* a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

int main() {

   Deque<int> d;
   d.push_front( 5 );
   d.push_front( 10 );
   d.push_front( 15 );
   d.Traverse();
   d.push_back( 20 );
   d.Traverse();
   cout<<"Front -> "<<d.front()<<" Back -> "<<d.back()<<"\n";

   d.pop_front();
   d.Traverse();
   d.pop_back();
   d.Traverse();
   return 0;
}
