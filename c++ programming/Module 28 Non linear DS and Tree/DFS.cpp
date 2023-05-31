#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int id;
   node* Left;
   node* Right;
   node* parent;
};

class BinaryTree {
 public:
   node* root;
   BinaryTree() {
      root = NULL;
   }

   node* CreateNewNode( int val ) {
      node* c_node = new node;
      c_node->id = val;
      c_node->Left = NULL;
      c_node->Right = NULL;
      c_node->parent = NULL;
      return c_node;
   }

   void Insertion( int val ) {
      node* new_node = CreateNewNode( val );
      if( root == NULL ) {
         root = new_node;
         return;
      }
      queue<node*>q;
      q.push( root );

      while( !q.empty() ) {
         node* a = q.front();
         q.pop();

         if( a->Left != NULL ) {
            q.push( a->Left );
         } else {
            a->Left = new_node;
            new_node->parent = a;
            return;
         }

         if( a->Right != NULL )
            q.push( a->Right );
         else {
            a->Right = new_node;
            new_node->parent = a;
            return;
         }
      }


   }

   void DFS( node* a ) {
      // this is the preorder traversal
      if( a == NULL )
         return;

      cout<<a->id<<" ";
      DFS( a->Left );
      DFS( a->Right );
   }

   void Inorder( node* a ) {
      if( a == NULL )
         return;

      Inorder( a->Left );
      cout<<a->id<<" ";
      Inorder( a->Right );
   }

   void Postorder( node* a ) {
      if( a == NULL )
         return;

      Postorder( a->Left );
      Postorder( a->Right );
      cout<<a->id<<" ";
   }


};

int main() {
   BinaryTree bn;
   bn.Insertion( 0 );
   bn.Insertion( 1 );
   bn.Insertion( 2 );
   bn.Insertion( 3 );
   bn.Insertion( 4 );
   bn.Insertion( 5 );
   cout<<"Pre-order traversal : ";
   bn.DFS( bn.root );
   cout<<"\n";
   cout<<"In-order traversal : ";
   bn.Inorder( bn.root );
   cout<<"\n";
   cout<<"Post-order traversal : ";
   bn.Postorder( bn.root );
   cout<<"\n";

   return 0;
}

/**
   @Full Binary Tree: Every node has 0 or 2 child
   @Complete Binary Tree: All levels are filled (2 childs) with nodes except last level nodes
   @Perfect Binary Tree: All levels are filled with nodes.
   @DFS - Depth first search which will search accordingly
   3 types of DFS
   @Inorder f(left child) + f(root) + f(right child)
   @Preorder f(root) + f(left child) + f(right child)
   @Postorder f(left child) + f(right child) + f(root)
*/

