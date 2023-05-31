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
   int rev;

   Deque() {
      head = NULL;
      tail = NULL;
      sz = 0;
      rev = 0;
   }

   node<T>* CreateNewNode( T val ) {
      node<T>* createdNode = new node<T>;
      createdNode->data = val;
      createdNode->nxt = NULL;
      createdNode->prv = NULL;
      return createdNode;
   }

   // push node at head O(1)
   void InsertAtHead(T val) {
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

   void InsertAtTail(T val){
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
   void pushFront( T val ) {
      if(rev == 0)
         InsertAtHead(val);
      else
         InsertAtTail(val);
   }
   // push node at tail O(1)
   void pushBack( T val ) {
      if(rev == 1)
         InsertAtHead(val);
      else
         InsertAtTail(val);
   }
   // pop node from head O(1)
   void RemoveFromHead(){
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
         head->prv = NULL;
      }

      delete a;
      sz--;
   }

   void RemoveFromTail(){
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
         tail->nxt = NULL;
      }

      delete a;
      sz--;
   }
   void popFront(){
      if(rev == 0)
         RemoveFromHead();
      else
         RemoveFromTail();
   }
   // pop node from tail O(1)
   void popBack(){
      if(rev == 1)
         RemoveFromHead();
      else
         RemoveFromTail();
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
      if(rev == 0)
         return head->data;
      else
         return tail->data;
   }

   T backData(){
      if(sz==0) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      if(rev == 1)
         return head->data;
      else
         return tail->data;
   }

   void reverse_deque() {
      if(rev == 0)
         rev = 1;
      else
         rev = 0;
   }
};

int main() {
   Deque<int> d;
   d.pushBack(5);
   d.pushBack(10);
   d.pushBack(15);
   d.reverse_deque();

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
