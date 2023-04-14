#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

class Solution {
private:
  bool check(TreeNode *left, TreeNode *right){
    if(!left || !right)
      return left == right;
    if(left->val == right->val) {
      return check(left->left, right->right) && check(left->right, right->left);
    }
    return false;
  };
public:
  bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return check(root->left, root->right);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0);
  Solution s;
  TreeNode *root = new TreeNode(1); 
  root -> left = new TreeNode(3); 
  root -> right = new TreeNode(3); 
  root -> left -> left = new TreeNode(4); 
  root -> left -> right = new TreeNode(6);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(4);
  
  if (s.isSymmetric(root)){
    cout<<"The binary tree is symmetric."<<endl;
  }
  else{
    cout<<"The binary tree is asymmetric."<<endl;
  }
  return 0;
  return 0;
}