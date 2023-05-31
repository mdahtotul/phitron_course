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

   void build_binary_tree() {
      node* allNode[6];
      for( int i=0; i<6; i++ )
         allNode[i] = CreateNewNode( i );

      allNode[0]->Left = allNode[1];
      allNode[0]->Right = allNode[2];

      allNode[1]->Left = allNode[5];
      allNode[1]->parent = allNode[0];

      allNode[2]->Left = allNode[3];
      allNode[2]->Right = allNode[4];
      allNode[2]->parent = allNode[0];

      allNode[5]->parent = allNode[1];

      allNode[3]->parent = allNode[2];

      allNode[4]->parent = allNode[2];

      root = allNode[0];
   }
   void BFS() {
      queue<node*>q;
      q.push( root );

      while( !q.empty() ) {
         node* a = q.front();
         q.pop();
         int p = -1, l = -1, r = -1;
         if( a->Left != NULL ) {
            l = a->Left->id;
            q.push( a->Left );
         }
         if( a->Right != NULL ) {
            r = a->Right->id;
            q.push( a->Right );
         }
         if( a->parent != NULL ) {
            p = a->parent->id;
         }
         cout<<"Node id = "<<a->id<<" ==> Left Child = "<<l<<" Right Child = "<<r<<" Parent id = "<<p<<"\n";
      }
   }
};

int main() {
   BinaryTree bn;
   bn.build_binary_tree();
   bn.BFS();
   return 0;
}

/**
   @Full Binary Tree: Every node has 0 or 2 child
   @Complete Binary Tree: All levels are filled (2 childs) with nodes except last level nodes
   @Perfect Binary Tree: All levels are filled with nodes.
   @BFS - Breadth first search which will do according to level
*/
