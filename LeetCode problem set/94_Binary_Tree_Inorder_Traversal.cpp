// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
//   void dfs(TreeNode* root, vector<int>& ans) {
//     if(!root) return;
//     dfs(root->left, ans);
//     ans.push_back(root->val);
//     dfs(root->right, ans);
//   }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//       vector<int> ans;
//       dfs(root, ans);
//       return ans;
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      TreeNode *cur = root;
      while (cur) {
        if(!cur->left){
          ans.push_back(cur->val);
          cur = cur->right;
        } else {
          TreeNode *prv = cur->left;
          while (prv->right && prv->right != cur)
            prv = prv->right;

          if(!prv->right){
            prv->right = cur;
            cur = cur->left;
          } else {
            ans.push_back(cur->val);
            prv->right = NULL;
            cur = cur->right;
          }
        }
      }
      return ans;
    }
};



int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}