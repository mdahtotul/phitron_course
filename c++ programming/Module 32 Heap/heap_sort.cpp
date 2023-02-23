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

   void down_heapify(int idx){
      while(1){
         int largest = idx;
         int left = 2*idx + 1;
         int right = 2*idx + 2;

         if(left < tree.size() && tree[left] > tree[largest])
            largest = left;

         if(right < tree.size() && tree[right] > tree[largest])
            largest = right;

         if(largest == idx)
            break;

         swap(tree[idx], tree[largest]);
         idx = largest;
      }
   }

   void Delete( int idx ) {
      if( tree.size() <= 0 ) {
         cout<<"Heap is empty!\n";
         return;
      }
      swap(tree[idx], tree[tree.size()-1]);
      tree.pop_back();
      down_heapify(idx);
   }

   void build_from_array(vector<int>&a){
      tree = a;
      int n = tree.size();
      int last_non_leaf = n/2 - 1;
      for(int i=last_non_leaf; i>=0; i--)
         down_heapify(i);
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

   int getMax() {
      if( tree.empty() ) {
         cout<<"Heap is empty!\n";
         return -1;
      }
      return tree[0];
   }

   int ExtractMax() {
      if( tree.empty() ) {
         cout<<"Heap is empty!\n";
         return -1;
      }
      int maxx = tree[0];
      Delete( 0 );
      return maxx;
   }

   int getSize(){
      return tree.size();
   }

};

vector<int> heap_sort(vector<int>a){
   MaxHeap hp;
   hp.build_from_array(a);
   vector<int>ans;
   for(int i=0; i<a.size(); i++){
      ans.push_back(hp.ExtractMax());
   }

   reverse(ans.begin(), ans.end());
   return ans;
}

class PriorityQueue{
public:
   MaxHeap mxHp;
   PriorityQueue(){
   }

   void push(int x){
      mxHp.Insert(x);
   }

   void pop(){
      mxHp.Delete(0);
   }

   int top(){
      return mxHp.getMax
   }

   int prSize(){
      return mxHp.getSize();
   }

};

int main() {
   MaxHeap mxHp;

   vector<int>a = {1,2,3,4,10,9,5,7};
   vector<int>sorted_a = heap_sort(a);
   for(int i=0; i<sorted_a.size(); i++)
      cout<<sorted_a[i]<<" ";

   cout<<"\n";

   return 0;
}
