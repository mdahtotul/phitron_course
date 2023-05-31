#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 100;

class Queue {
 public:
   int a[mx_sz];
   int l;
   int r;
   int sz;

   Queue() {
      l = 0;
      r = -1;
      sz = 0;
   }

   void enqueue( int val ) {
      if( r+1 == mx_sz ) {
         cout<<"Maximum capacity reached!\n";
         return ;
      }

      r++;
      if( r == mx_sz ) {
         r=0;
      }
      a[r] = val;
      sz++;
   }

   void dequeue() {
      if( sz==0 ) {
         cout<<"Queue is empty!\n";
         return;
      }
      a[l] = 0;
      l++;
      if( l == mx_sz )
         l=0;
      sz--;
   }

   int front() {
      if( sz==0 ) {
         cout<<"Queue is empty!\n";
         return -1;
      }
      return a[l];
   }

   int getSize() {
      return sz;
   }
};

int main() {
   Queue q;
   q.enqueue( 10 );
   q.enqueue( 6 );
   q.enqueue( 12 );

   cout<<"Queue size = "<<q.getSize()<<"\n";

   cout<<q.front()<<"\n";
   q.dequeue();
   cout<<q.front()<<"\n";
   q.dequeue();
   cout<<q.front()<<"\n";
   q.dequeue();
   cout<<"Queue size = "<<q.getSize()<<"\n";
   return 0;
}
