#include <bits/stdc++.h>
using namespace std;


template<class T>
class Queue {
 public:
   T *arr;
   int l, r;
   int sz;
   int arr_cap;

   Queue() {
      arr = new T[1];
      l=0;
      r=-1;
      sz=0;
      arr_cap=0;
   }

   void removeCircular() {
      if( l>r ) {
         T *tmp = new T[arr_cap];
         int idx = 0;
         for( int i=l; i<arr_cap; i++ ) {
            tmp[idx] = arr[i];
            idx++;
         }
         for( int i=0; i<r; i++ ) {
            tmp[idx] = arr[i];
            idx++;
         }

         swap( tmp, arr );
         l=0;
         r=arr_cap-1;
         delete []tmp;
      }
   }

   void increaseSize() {
      removeCircular();
      T *tmp = new T[arr_cap*2];
      for( int i=0; i<arr_cap; i++ )
         tmp[i] = arr[i];

      swap( tmp, arr );
      arr_cap = arr_cap*2;
      delete []tmp;
   }

   void enqueue( T val ) {
      if( sz == arr_cap ) {
         increaseSize();
      }
      r++;
      if( r == arr_cap ) {
         r=0;
      }
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
      if( l==arr_cap )
         l=0;

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
}
