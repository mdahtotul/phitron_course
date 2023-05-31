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
public:
    int maxDepth(TreeNode* root) {
      if(!root)
        return 0;
      int leftDepth = maxDepth(root->left);
      int rightDepth = maxDepth(root->right);
      return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0);
  Solution s;

  TreeNode *root = new TreeNode(0);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(20);
  root -> right -> left = new TreeNode(15);
  root -> right -> right = new TreeNode(7);


  cout<<s.maxDepth(root)<<"\n";
  return 0;
}