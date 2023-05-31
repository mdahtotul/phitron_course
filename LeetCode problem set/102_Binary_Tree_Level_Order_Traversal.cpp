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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ans;
      if(!root) return ans;
      
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
        int sz = q.size();
        vector<int> level;
        while(sz--) {
          TreeNode *cur = q.front();
          level.push_back(cur->val);
          q.pop();
          if(cur->left) 
            q.push(cur->left);

          if(cur->right) 
            q.push(cur->right);

        }
        ans.push_back(level);
      }
      return ans;
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

  vector<vector<int>> ans = s.levelOrder(root);
  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}