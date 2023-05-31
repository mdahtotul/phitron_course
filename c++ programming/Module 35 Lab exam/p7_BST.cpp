#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int value;
   node* Left;
   node* Right;
};


class BST {
 public:
   node *root;
   BST() {
      root = NULL;
   }

   node* CreateNewNode( int val ) {
      node* new_node = new node;
      new_node->value = val;
      new_node->Left = NULL;
      new_node->Right = NULL;
      return new_node;
   }

   void Insert( int value ) {
      node* c_node = CreateNewNode( value );
      if( root == NULL ) {
         root = c_node;
         return;
      }

      node* cur = root;
      node* prv = NULL;

      while( cur != NULL ) {
         if( c_node->value > cur->value ) {
            prv = cur;
            cur = cur->Right;
         } else {
            prv = cur;
            cur = cur->Left;
         }
      }

      if( c_node->value > prv->value )
         prv->Right = c_node;
      else
         prv->Left = c_node;
   }
   bool Search( int value ) {
      if(root == NULL){
         cout<<"Tree is empty!\n";
         return false;
      }

      node* cur = root;
      while(cur != NULL){
         if(cur->value > value)
            cur = cur->Left;
         else if (cur->value < value)
            cur = cur->Right;
         else
            return true;
      }
      return false;
   }
};
int main() {
   BST bst;
   bst.Insert( 10 );
   bst.Insert( 20 );
   bst.Insert( 25 );
   bst.Insert( 50 );
   bst.Insert( 8 );
   bst.Insert( 9 );
   cout<<bst.Search( 10 )<<"\n"; //1
   cout<<bst.Search( 9 )<<"\n"; //1
   cout<<bst.Search( 20 )<<"\n"; //1
   cout<<bst.Search( 60 )<<"\n"; //0
   return 0;
}
