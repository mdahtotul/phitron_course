#include <bits/stdc++.h>
using namespace std;

class Heap {
 public:

   vector<int>nodes;

   Heap() {
   }

   void up_heapify( int idx ) {
      while( idx > 0 && nodes[idx] > nodes[( idx-1 )/2] ) {

         swap( nodes[idx], nodes[( idx-1 )/2] );
         idx = ( idx-1 )/2;
      }
   }

   // TC: O(logn)
   void insert( int x ) {
      nodes.push_back( x ); // TC: O(1)
      up_heapify( nodes.size()-1 );
   }

   void PrintHeap() {
      for( int i=0; i<nodes.size(); i++ ) {
         cout<<nodes[i]<<" ";
      }
      cout<<"\n";
   }

   // TC: O(logn)
   void down_heapify( int idx ) {
      while( 1 ) {
         int largest = idx;
         int l = 2*idx + 1;
         int r = 2*idx + 2;
         if( l<nodes.size() && nodes[largest]<nodes[l] ) {
            largest=l;
         }
         if( l<nodes.size() && nodes[largest]<nodes[r] ) {
            largest=r;
         }
         if( largest == idx )
            break;
         swap( nodes[idx], nodes[largest] );
         idx = largest;
      }
   }

   void Delete( int idx ) {
      if( idx >= nodes.size() )
         return;
      swap( nodes[idx], nodes[nodes.size()-1] );
      nodes.pop_back();
      down_heapify( idx );
   }

   int getMax() {
      if( nodes.empty() ) {
         cout<<"Heap is empty!\n";
         return -1;
      }
      return nodes[0];
   }

   int ExtractMax() {
      if( nodes.empty() ) {
         cout<<"Heap is empty!\n";
         return -1;
      }
      int ret = nodes[0];
      Delete( 0 );
      return ret;
   }

   void build_form_array( vector<int>&a ) {
      nodes = a;
      int n = nodes.size();
      int last_non_leaf = n/2 - 1;
      for( int i=last_non_leaf; i>=0; i-- )
         down_heapify( i );
   }
};

int main() {

   Heap heap;
/**
   heap.insert( 4 );
   heap.insert( 7 );
   heap.insert( 9 );
   heap.insert( 1 );
   heap.insert( 10 );
   heap.insert( 20 );
   heap.insert( 30 );
   heap.PrintHeap();

   cout<<"Max element = "<<heap.getMax()<<"\n";
   cout<<"Max element = "<<heap.ExtractMax()<<"\n";
   cout<<"Max element = "<<heap.getMax()<<"\n";

   //heap.Delete( 0 );
*/
   vector<int>a = {1,2,3,4,10,9,8,7};
   heap.build_form_array(a);
   heap.PrintHeap();

   return 0 ;
}

/**
   @Heap is a complete binary tree.
*/
