#include <bits/stdc++.h>
using namespace std;

const int mx_sz = 10;

template<class T>
class Queue {
 public:
   T arr[mx_sz];
   int l;
   int r;
   int sz;

   Queue() {
      l=0;
      r=-1;
      sz=0;
   }

   void enqueue( T val ) {
      if( r+1 >= mx_sz ) {
         cout<<"Maximum capacity exicted!\n";
         return;
      }
      r++;
      if( r == mx_sz )
         r = 0;

      arr[r] = val;
      sz++;
   }

   void dequeue() {
      if( sz == 0 ) {
         cout<<"Queue is empty\n";
         return;
      }
      arr[l] = 0;
      l++;
      if( l == mx_sz )
         l = 0;

      sz--;
   }

   T front_que() {
      if( sz == 0 ) {
         cout<<"Queue is empty\n";
         T a;
         return a;
      }

      return arr[l];
   }

   int getSize() {
      return sz;
   }
};

int main() {
   Queue<int> q;
   q.enqueue( 12 );
   q.enqueue( 8 );
   q.enqueue( 16 );

   cout<<"Queue size = "<<q.getSize()<<"\n";

   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<q.front_que()<<"\n";
   q.dequeue();
   cout<<"Queue size = "<<q.getSize()<<"\n";

   Queue<double> q1;
   q1.enqueue( 12.7 );
   q1.enqueue( 8.7 );
   q1.enqueue( 16.9 );

   cout<<"Queue size = "<<q1.getSize()<<"\n";

   cout<<q1.front_que()<<"\n";
   q1.dequeue();
   cout<<q1.front_que()<<"\n";
   q.dequeue();
   cout<<q1.front_que()<<"\n";
   q1.dequeue();
   cout<<"Queue size = "<<q1.getSize()<<"\n";

   return 0;
   return 0;
}
