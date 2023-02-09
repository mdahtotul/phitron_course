#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
 public:
   T *a;
   int sz;
   int arr_cap;
   int l;
   int r;

   Queue() {
      a = new T[1];
      sz = 0;
      arr_cap = 0;
      l = 0;
      r = -1;
   }

   void removeCircular() {
      if( l>r ) {
         T *tmp = new T[arr_cap];
         int idx = 0;
         for( int i=l; i<arr_cap; i++ ) {
            tmp[idx] = a[i];
            idx++;
         }
         for( int i=0; i<r; i++ ) {
            tmp[idx] = a[i];
            idx++;
         }
         swap( a, tmp );
         delete []tmp;
         l=0;
         r=arr_cap-1;
      }
   }

   void increaseSize() {
      removeCircular();
      T *tmp = new T[arr_cap*2];
      for( int i=0; i<arr_cap; i++ )
         tmp[i] = a[i];

      swap( a, tmp );
      delete []tmp;
      arr_cap = arr_cap*2;
   }

   void decreaseSize() {
      removeCircular();
      T *tmp = new T[arr_cap/2];
      for( int i=0; i<arr_cap; i++ )
         tmp[i] = a[i];

      swap( a, tmp );
      delete []tmp;
      arr_cap = arr_cap/2;
   }

   void enqueue(T val) {
      if(sz == arr_cap) {
         increaseSize();
      }

      r++;
      if(r == arr_cap)
         r = 0;
      a[r] = val;
      sz++;
   }

   void dequeue() {
      if(sz == 0) {
         cout<<"Queue is empty!\n";
         return ;
      }
      if(sz == arr_cap/2) {
         decreaseSize();
      }

      a[l] = 0;
      l++;
      if(l == arr_cap)
         l=0;

      sz--;
   }

   T front(){
      if(sz == 0)
      {
         cout<<"Queue is empty!\n";
         T a;
         return a;
      }
      return a[l];
   }

};

int main() {
   Queue<int> q;
   q.enqueue( 12 );
   q.enqueue( 8 );
   q.enqueue( 16 );

   cout<<q.front()<<"\n";
   q.dequeue();
   cout<<q.front()<<"\n";
   q.dequeue();
   cout<<q.front()<<"\n";
   q.dequeue();

   return 0;
}
