#include <bits/stdc++.h>
using namespace std;

class node {
 public:
   int value;
   node* left;
   node* right;
};

class BST {
 public:
   node* root;

   BST() {
      root = NULL;
   }

   node* CreateNewNode( int val ) {
      node* newNode = new node;
      newNode->value = val;
      newNode->left = NULL;
      newNode->right = NULL;

      return newNode;
   }

   void Insert( int val ) {
      node* c_node = CreateNewNode( val );

      if( root == NULL ) {
         root = c_node;
         return;
      }

      node* cur = root;
      node* prv = NULL;

      while( cur != NULL ) {
         if( c_node->value > cur->value ) {
            prv = cur;
            cur = cur->right;
         } else {
            prv = cur;
            cur = cur->left;
         }
      }
      if( c_node->value > prv->value ) {
         prv->right = c_node;
      } else {
         prv->left = c_node;
      }
   }

   void BFS() {
      if( root == NULL )
         return;

      queue<node*> q;
      q.push( root );

      while( !q.empty() ) {
         node* a = q.front();
         q.pop();

         int l=-1,
             r=-1;
         if( a->left != NULL ) {
            l = a->left->value;
            q.push( a->left );
         }

         if( a->right != NULL ) {
            r = a->right->value;
            q.push( a->right );
         }

         cout<<"Node value = "<<a->value<<" ==> Left child = "<<l<<" Right child = "<<r<<"\n";
      }
   }

   bool Search( int val ) {
      node* cur = root;
      while( cur != NULL ) {
         if( val > cur->value ) {
            cur = cur->right;
         } else if ( val < cur->value ) {
            cur = cur->left;
         } else {
            return true;
         }
      }
      return false;
   }

   void Delete( int val ) {
      node* cur = root;
      node* prv = NULL;

      while( cur != NULL ) {
         if( val > cur->value ) {
            prv = cur;
            cur = cur->right;
         } else if( val < cur->value ) {
            prv = cur;
            cur = cur->left;
         } else {
            break;
         }
      }
      if( cur == NULL ) {
         cout<<"Value is not present in BST\n";
         return;
      }

      //Case-1: Node has no child
      if( cur->left == NULL && cur->right == NULL ) {
         if( prv->left!=NULL && prv->left->value == cur->value ) {
            prv->left = NULL;
         } else {
            prv->right = NULL;
         }
         delete cur;
         return;
      }
      //Case-2: Node has one child
      if( cur->left == NULL && cur->right != NULL ) {
         if( prv->left!=NULL && prv->left->value == cur->value ) {
            prv->left = cur->right;
         } else {
            prv->right = cur->right;
         }
         delete cur;
         return;
      }
      if( cur->left != NULL && cur->right == NULL ) {
         if( prv->left!=NULL && prv->left->value == cur->value ) {
            prv->left = cur->left;
         } else {
            prv->right = cur->left;
         }
         delete cur;
         return;
      }

      //Case-3: Node has both child
      node* tmp = cur->right;
      while(tmp->left != NULL){
         tmp = tmp->left;
      }
      int saved = tmp->value;
      Delete(saved);
      cur->value = saved;
   }
};


int main() {

   BST bst;
   bst.Insert( 6 );
   bst.Insert( 4 );
   bst.Insert( 3 );
   bst.Insert( 5 );
   bst.Insert( 7 );
   bst.Insert( 8 );

   //bst.BFS();

   //cout<<bst.Search( 1 )<<"\n";
   //cout<<bst.Search( 3 )<<"\n";
   //case 1
   //bst.Delete( 8 );
   //case 2
   //bst.Delete( 7 );
   //case 3
   //bst.Delete(6);
   bst.BFS();
   return 0;
}

/**
   @BinarySearchTree - left sub tree <= root && root<= right sub tree

   @Deletion Case -
      1/ No child
      2/ One child
      3/ Two child
*/
