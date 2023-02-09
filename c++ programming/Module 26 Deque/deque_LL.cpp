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

   node<T>* CreateNewNode( T val ) {
      node<T>* createdNode = new node<T>;
      createdNode->data = val;
      createdNode->nxt = NULL;
      createdNode->prv = NULL;
      return createdNode;
   }

   // push node at head O(1)
   void pushFront( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz==0 ) {
         head = newNode;
         tail = newNode;
      }
      newNode->nxt = head;
      head->prv = newNode;
      head = newNode;
      sz++;
   }
   // push node at tail O(1)
   void pushBack( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz == 0 ) {
         head = newNode;
         tail = newNode;
      }

      tail->nxt = newNode;
      newNode->prv = tail;
      tail = newNode;
      sz++;
   }
   // pop node from head O(1)
   void popFront(){
      if(sz == 0)
      {
         cout<<"Deque is empty!\n";
         return;
      }
      if(sz == 1) {

         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }

      node<T>* a = head;
      node<T>* b = head->nxt;
      if(b != NULL)
      {
         head = b;
         b->prv = NULL;
      }

      delete a;
      sz--;
   }
   // pop node from tail O(1)
   void popBack(){
      if(sz == 0)
      {
         cout<<"Deque is empty!\n";
         return;
      }
      if(sz == 1) {

         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }

      node<T>* a = tail;
      node<T>* b = tail->prv;
      if(b != NULL)
      {
         tail = b;
         b->nxt = NULL;
      }

      delete a;
      sz--;
   }

   void Traverse() {
      node<T>* a = head;
      while(a != NULL)
      {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }

   T frontData(){
      if(sz==0) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return head->data;
   }

   T backData(){
      if(sz==0) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return tail->data;
   }
};

int main() {
   Deque<int> d;
   d.pushBack(5);
   d.pushBack(10);
   d.pushBack(15);

   cout<<"Back : "<<d.backData()<<" Front : "<<d.frontData()<<"\n";

   d.pushFront(20);
   cout<<"Back : "<<d.backData()<<" Front : "<<d.frontData()<<"\n";

   d.Traverse();

   d.popFront();
   cout<<"Back : "<<d.backData()<<" Front : "<<d.frontData()<<"\n";

   d.popBack();
   cout<<"Back : "<<d.backData()<<" Front : "<<d.frontData()<<"\n";

   d.Traverse();
   return 0;
}
