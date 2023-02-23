 #include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int id;
   int data;
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

   node* CreateNewNode( int val, int data ) {
      node* c_node = new node;
      c_node->id = val;
      c_node->data = data;
      c_node->Left = NULL;
      c_node->Right = NULL;
      c_node->parent = NULL;
      return c_node;
   }

   void Insertion( int val, int data ) {
      node* new_node = CreateNewNode( val, data );
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

   void BFS() {
      if(root == NULL)
         return;

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

   void Search(node* a, int val){
      if(a==NULL)
         return;
      if(a->data == val)
      {
         cout<<"Search found at "<<a->id<<" ";
      }
      Search(a->Left, val);
      Search(a->Right, val);
   }
};

int main() {
   BinaryTree bn;
   bn.Insertion( 0, 5 );
   bn.Insertion( 1, 10 );
   bn.Insertion( 2, 10 );
   bn.Insertion( 3, 9 );
   bn.Insertion( 4, 8 );
   bn.Insertion( 5, 5 );
   bn.Insertion( 6, 7 );
   bn.BFS();
   cout<<"\n\n\n\n";
   cout<<"Pre-order traversal : ";
   bn.DFS( bn.root );
   cout<<"\n";
   cout<<"In-order traversal : ";
   bn.Inorder( bn.root );
   cout<<"\n";
   cout<<"Post-order traversal : ";
   bn.Postorder( bn.root );
   cout<<"\n";

   bn.Search(bn.root, 5);
   cout<<"\n";
   bn.Search(bn.root, 10);
   cout<<"\n";

   return 0;
}

/**
   @Full Binary Tree: Every node has 0 or 2 child
   @Complete Binary Tree: All levels are filled (2 childs) with nodes except last level nodes
   @Perfect Binary Tree: All levels are filled with nodes.
   @BFS - Breadth first search which will do according to level
   @DFS - Depth first search which will search accordingly
   3 types of DFS
   @Inorder f(left child) + f(root) + f(right child)
   @Preorder f(root) + f(left child) + f(right child)
   @Postorder f(left child) + f(right child) + f(root)
*/

