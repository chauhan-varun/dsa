
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
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};

    queue<TreeNode *> q;
    vector<vector<int>> ans;

    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> temp;
      for (int i = 0; i < n; i++) {
        auto node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        temp.push_back(node->val);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
