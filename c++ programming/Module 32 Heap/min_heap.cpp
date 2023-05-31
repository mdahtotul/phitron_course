#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
   vector<int> tree;
   MinHeap(){
   }

   void up_heapify(int idx){
      while(idx>0 && tree[idx] < tree[(idx-1)/2]) {
         swap(tree[idx], tree[(idx-1)/2]);
         idx = (idx-1)/2;
      }
   }

   void Insert(int val){
      tree.push_back(val);
      up_heapify(tree.size()-1);
   }

   void down_heapify(int idx) {
      while( 1 ) {
         int smallest = idx;
         int left = 2*idx + 1;
         int right = 2*idx + 2;

         if( left < tree.size() && tree[left] < tree[smallest] )
            smallest = left;

         if( right < tree.size() && tree[right] < tree[smallest] )
            smallest = right;

         if( smallest == idx )
            break;

         swap( tree[idx], tree[smallest] );
         idx = smallest;
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
};

int main(){
   MinHeap minHp;

   minHp.Insert( 4 );
   minHp.Insert( 7 );
   minHp.Insert( 9 );
   minHp.Insert( 1 );
   minHp.Insert( 10 );
   minHp.Insert( 20 );
   minHp.Insert( 30 );
   minHp.PrintHeap();

   minHp.Delete(3);
   minHp.PrintHeap();
   return 0;
}
