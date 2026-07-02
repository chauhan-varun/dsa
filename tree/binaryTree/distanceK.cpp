#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  queue<TreeNode *> q;
  unordered_map<TreeNode *, TreeNode *> mpp;
  TreeNode *x;

  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      q.pop();
      if (target->val == node->val)
        x = node;

      if (node->left) {
        q.push(node->left);
        mpp[node->left] = node;
      }
      if (node->right) {
        q.push(node->right);
        mpp[node->right] = node;
      }
    }
  }
  
  unordered_map<int, bool> vis;
  q.push(x);
  vis[x->val] = 1;
  
  while (k-- && !q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left && !vis[node->left->val]) {
        vis[node->left->val] = 1;
        q.push(node->left);
      }
      if (node->right && !vis[node->right->val]) {
        vis[node->right->val] = 1;
        q.push(node->right);
      }
      if (mpp.find(node) != mpp.end() && !vis[mpp[node]->val]) {
        vis[mpp[node]->val] = 1;
        q.push(mpp[node]);
      }
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.front()->val);
    q.pop();
  }
  return ans;
}
