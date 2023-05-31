#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
 public:
   MaxHeap() {}

   vector<int>tree;

   void up_heapify( int idx ) {
      while( idx > 0 && tree[idx] > tree[( idx-1 )/2] ) {
         swap( tree[idx], tree[( idx-1 )/2] );
         idx = ( idx-1 )/2;
      }
   }

   void Insert( int val ) {
      tree.push_back( val );
      up_heapify( tree.size()-1 );
   }

   void down_heapify( int idx ) {
      while( 1 ) {
         int largest = idx;
         int left = 2*idx + 1;
         int right = 2*idx + 2;

         if( left < tree.size() && tree[left] > tree[largest] )
            largest = left;

         if( right < tree.size() && tree[right] > tree[largest] )
            largest = right;

         if( largest == idx )
            break;

         swap( tree[idx], tree[largest] );
         idx = largest;
      }
   }

   void Delete( int idx ) {
      if( tree.size() <= 0 ) {
         cout<<"Heap is empty!\n";
         return;
      }
      swap( tree[idx], tree[tree.size()-1] );
      tree.pop_back();
      down_heapify( idx );
   }

   int getMax() {
      if( tree.empty() ) {
         cout<<"Heap is empty!\n";
         return -1;
      }
      return tree[0];
   }

   void PrintHeap() {
      if( tree.size() <= 0 ) {
         cout<<"Heap is empty!\n";
         return;
      }
      for( int i=0; i<tree.size(); i++ ) {
         cout<<tree[i]<<" ";
      }
      cout<<"\n";
   }

   void PrintInvHeap() {
      if( tree.size() <= 0 ) {
         cout<<"Heap is empty!\n";
         return;
      }
      for( int i=0; i<tree.size(); i++ ) {
         cout<<tree[i]*( -1 )<<" ";
      }
      cout<<"\n";
   }
};

class MinHeap {
 public:
   MaxHeap mx;
   void insert( int x ) {
      mx.Insert( x*( -1 ) );
   }
   void Delete( int idx ) {
      mx.Delete( idx );
   }
   int getMin() {
      return ( -1 )*mx.getMax();
   }
   void print() {
      mx.PrintInvHeap();
   }
};


int main() {

   MinHeap heap;

   heap.insert( 4 );
   heap.insert( 7 );
   heap.insert( 9 );
   heap.insert( 1 );
   heap.insert( 10 );
   heap.insert( 20 );
   heap.insert( 30 );
   heap.print();
   cout<<"Min = "<<heap.getMin()<<"\n";
   heap.Delete( 1 );
   heap.print();
   return 0;
}
