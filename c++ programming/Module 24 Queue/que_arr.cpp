#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 500;

class Queue {
 public:
   int a[mx_sz];
   int l,r;

   Queue () {
      l=0;
      r=-1;
   }

   void enqueue( int val ) {
      if( r+1 >= mx_sz ) {
         cout<<"Queue is full\n";
         return;
      }
      r++;
      a[r] = val;
   }
   void dequeue() {
      if( l > r ) {
         cout<<"Queue is empty\n";
         return;
      }
      a[l] = 0;
      l++;
   }

   int front_que() {
      if( l > r ) {
         cout<<"Queue is empty\n";
         return -1;
      }
      return a[l];
   }

   int getSize() {
      return r-l+1;
   }
};

int main() {
   Queue q;
   q.enqueue( 5 );
   q.enqueue( 6 );
   q.enqueue( 7 );

   cout<<"Queue size = "<<q.getSize()<<"\n";

   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<"Queue size = "<<q.getSize()<<"\n";

   return 0;
}
