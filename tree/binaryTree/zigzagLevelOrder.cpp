#include <bits/stdc++.h>
#include <queue>
#include <vector>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  if (!root)
    return {};

  vector<vector<int>> ans;
  queue<TreeNode *> q;
  bool flag = true;

  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      q.pop();
      int idx = flag? i: n-i-1;
      temp[i]=node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    flag = !flag;
    ans.push_back(temp);
  }
  return ans;
}
