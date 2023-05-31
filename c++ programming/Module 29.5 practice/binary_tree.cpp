#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int id;
   int data;
   node* left;
   node* right;
   node* parent;
};

class BinaryTree {
 public:
   node* root;
   int sz;

   BinaryTree() {
      root = NULL;
      sz = 0;
   }

   node* CreateNode( int Id, int Val ) {
      node* new_node = new node;
      new_node->id = Id;
      new_node->data = Val;
      new_node->left = NULL;
      new_node->right = NULL;
      new_node->parent = NULL;

      return new_node;
   }

   void Insertion( int id, int val ) {
      node* newNode = CreateNode( id, val );
      if( root == NULL ) {
         root = newNode;
         return;
      }

      queue<node*>q;
      q.push( root );

      while( !q.empty() ) {
         node* a = q.front();
         q.pop();

         if( a->left != NULL ) {
            q.push( a->left );
         } else {
            a->left = newNode;
            newNode->parent = a;
            return;
         }

         if( a->right != NULL ) {
            q.push( a->right );
         } else {
            a->right = newNode;
            newNode->parent = a;
            return;
         }
      }
   }

   void Search(node* a, int val) {
      if(a == NULL) {
         return;
      }

      if(a->data == val)
      {
         cout<<"Search found id -> "<<a->id<<" value -> "<<a->data<<"\n";
      }

      Search(a->left, val);
      Search(a->right, val);
   }

   void BFS(){
      if(root == NULL)
         return;

      queue<node*> q;
      q.push(root);

      while(!q.empty()){
         node* a = q.front();
         q.pop();
         int p=-1, r=-1, l=-1;
         if(a->left != NULL){
            l = a->left->id;
            q.push(a->left);
         }

         if(a->right != NULL){
            r = a->right->id;
            q.push(a->right);
         }

         if(a->parent != NULL)
            p = a->parent->id;

         cout<<"Node id/level = "<<a->id<<" ==> Left child = "<<l<<" Right child = "<<r<<" Parent "<<p<<"\n";
      }
   }

   int maxDepth(node* a){
      if(a == NULL)
         return 0;

      int lDepth = maxDepth(a->left);
      int rDepth = maxDepth(a->right);

      if(lDepth > rDepth)
         return (lDepth+1);
      else
         return (rDepth+1);
   }

   bool isPerfectLeaves(node* a, int h, int level=0){
      if(a==NULL)
         return true;

      if(a->left == NULL && a->right == NULL)
         return (h == level+1);

      if(a->left == NULL || a->right == NULL)
         return false;

      return isPerfectLeaves(a->left, h, level+1) && isPerfectLeaves(a->right, h, level+1);
   }

   bool isPerfect(node* a){
      int h = maxDepth(a);
      return isPerfectLeaves(a, h);
   }

   void DFS(node* a) {
      if(a == NULL)
         return;

      cout<<a->id<<" ";
      DFS(a->left);
      DFS(a->right);
   }

   void Inorder(node* a){
      if(a == NULL)
         return;
      Inorder(a->left);
      cout<<a->id<<" ";
      Inorder(a->right);
   }

   void Postorder(node* a){
      if(a == NULL)
         return;

      Postorder(a->left);
      Postorder(a->right);
      cout<<a->id<<" ";
   }

};

int main() {
   BinaryTree bt;
   bt.Insertion(0, 5);
   bt.Insertion(1, 10);
   bt.Insertion(2, 10);
   bt.Insertion(3, 9);
   bt.Insertion(4, 8);
   bt.Insertion(5, 5);
   bt.Insertion(6, 7);

   bt.BFS();
   cout<<"\n\n\n\n";
   cout<<"Pre-order traversal : ";
   bt.DFS( bt.root );
   cout<<"\n";
   cout<<"In-order traversal : ";
   bt.Inorder( bt.root );
   cout<<"\n";
   cout<<"Post-order traversal : ";
   bt.Postorder( bt.root );

   cout<<"\nBinary tree height = "<<bt.maxDepth(bt.root)<<"\n";

   cout<<"Que: Is perfect tree ? Ans: ";
   if (bt.isPerfect(bt.root))
        printf("Yes\n");
    else
        printf("No\n");
   cout<<"\n";
   return 0;
}
