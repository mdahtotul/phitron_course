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

   node* CreateNewNode(int val){
      node* c_node = new node;
      c_node->id = val;
      c_node->Left = NULL;
      c_node->Right = NULL;
      c_node->parent = NULL;
      return c_node;
   }

   void build_binary_tree() {
      node* allNode[6];
      for(int i=0; i<6; i++)
         allNode[i] = CreateNewNode(i);

      allNode[0]->Left = allNode(1);
      allNode[0]->Right = allNode(2);

      allNode[1]->Left = allNode(5);
      allNode[1]->parent = allNode(0);

      allNode[2]->Left = allNode(3);
      allNode[2]->Right = allNode(4);
      allNode[2]->parent = allNode(0);

      allNode[5]->parent = allNode(1);

      allNode[3]->parent = allNode(2);

      allNode[4]->parent = allNode(2);
   }
   void print_tree_info(){
      int p=-1;
      int l=-1;
      int r=-1;

      if(allNo)
   }
};

int main()
{
   return 0;
}

/**
   @Full Binary Tree: Every node has 0 or 2 child
   @Complete Binary Tree: All levels are filled (2 childs) with nodes except last level nodes
   @Perfect Binary Tree: All levels are filled with nodes.
*/
