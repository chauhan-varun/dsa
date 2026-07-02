#include <bits/stdc++.h>
#include <queue>
#include <utility>
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
vector<int> rightSideView(TreeNode *root) {
  if (!root)
    return {};
  vector<int> ans;
  queue<pair<TreeNode *, int>> q;

  q.push({root, 0});
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto [node, lvl] = q.front();
      q.pop();
      if (ans.size() == lvl)
        ans.push_back(node->val);

      if (node->right)
        q.push({node->right, lvl + 1});
      if (node->left)
        q.push({node->left, lvl + 1});
    }
  }
  return ans;
}
