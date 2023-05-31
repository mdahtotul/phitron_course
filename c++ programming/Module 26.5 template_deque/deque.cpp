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
      node<T>* c_node = new node<T>;
      c_node->data = val;
      c_node->nxt = NULL;
      c_node->prv = NULL;
      return c_node;
   }

   void InsertAtHead( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz == 0 ) {
         head = newNode;
         tail = newNode;
         sz++;
         return;
      }

      newNode->nxt = head;
      newNode->prv = NULL;
      head->prv = newNode;
      head = newNode;
      sz++;
   }

   void InsertAtTail( T val ) {
      node<T>* newNode = CreateNewNode( val );
      if( sz == 0 ) {
         head = newNode;
         tail = newNode;
         sz++;
         return;
      }

      newNode->prv = tail;
      newNode->nxt = NULL;
      tail->nxt = newNode;
      tail = newNode;
      sz++;
   }

   void pushFront( T val ) {
      rev == 0 ? InsertAtHead( val ) : InsertAtTail( val );
   }

   void pushBack( T val ) {
      rev == 1 ? InsertAtHead( val ) : InsertAtTail( val );
   }

   void RemoveFromHead() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         return;
      }
      if( sz==1 ) {
         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }
      node<T>* a = head;
      node<T>* b = head->nxt;
      if( b != NULL ) {
         head = b;
         b->prv = NULL;
      }
      delete a;
      sz--;
   }

   void RemoveFromTail() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         return;
      }
      if( sz==1 ) {
         delete head;
         head = NULL;
         tail = NULL;
         sz--;
         return;
      }
      node<T>* a = tail;
      node<T>* b = tail->prv;
      if( b != NULL ) {
         tail = b;
         b->nxt = NULL;
      }
      delete a;
      sz--;
   }

   void popFront() {
      rev == 0 ? RemoveFromHead() : RemoveFromTail();
   }

   void popBack() {
      rev == 1 ? RemoveFromHead() : RemoveFromTail();
   }

   T getHead() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return head->data;
   }

   T getTail() {
      if( sz == 0 ) {
         cout<<"Deque is empty!\n";
         T a;
         return a;
      }
      return tail->data;
   }

   T frontData() {
      if( rev == 0 ) {
         return getHead();
      } else {
         return getTail();
      }
   }

   T backData() {
      if( rev == 1 ) {
         return getHead();
      } else {
         return getTail();
      }
   }

   void Traverse() {
      node<T>* a = head;
      while( a != NULL ) {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }

   T getMax() {
      node<T>* a = head;
      T maxx = head->data;
      while( a != NULL ) {
         T val = a->data;
         if( val > maxx )
            maxx = val;

         a = a->nxt;
      }
      return maxx;
   }

   T getMin() {
      node<T>* a = head;
      T minn = head->data;
      while( a != NULL ) {
         T val = a->data;
         if( val < minn )
            minn = val;

         a = a->nxt;
      }
      return minn;
   }

   int getSize() {
      return sz;
   }

};

int main() {
   Deque<int> d1;
   d1.pushFront( 5 );
   d1.pushFront( 10 );
   d1.pushFront( 15 );
   d1.Traverse();
   cout<<"Deque size -> "<<d1.getSize()<<"\n";
   d1.pushBack( 20 );
   d1.pushFront( 0 );
   d1.Traverse();
   cout<<"Max data -> "<<d1.getMax()<<"\n";
   cout<<"Min data -> "<<d1.getMin()<<"\n";
   cout<<"Deque size -> "<<d1.getSize()<<"\n";
   d1.popFront();
   d1.popBack();
   d1.Traverse();
   cout<<"Deque size -> "<<d1.getSize()<<"\n";
   cout<<"Front data -> "<<d1.frontData()<<"\n";
   cout<<"Back data -> "<<d1.backData()<<"\n";

   cout<<"\n<===============================>\n\n";
   Deque<char> d2;
   d2.pushFront( 'b' );
   d2.pushFront( 'a' );
   d2.pushFront( 'c' );
   d2.Traverse();
   cout<<"Deque size -> "<<d2.getSize()<<"\n";
   d2.pushBack( 'e' );
   d2.pushFront( 'd' );
   d2.Traverse();
   cout<<"Max data -> "<<d2.getMax()<<"\n";
   cout<<"Min data -> "<<d2.getMin()<<"\n";

   return 0;
}
