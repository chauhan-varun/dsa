#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
  // 
};

vector<vector<int>> levelOrder(TreeNode* root){
  vector<vector<int>> v;
  queue<TreeNode*> q;
  if(!root) return {};
  
  q.push(root);

  while(!q.empty()){
    int n = q.size();
    vector<int> temp;\

    for(int i = 0; i<n; i++){
      TreeNode* node = q.front();
      q.pop();
      temp.push_back(node->val);
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }
    v.push_back(temp);
  }
  return v;
}
