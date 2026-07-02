#include <bits/stdc++.h>
#include <string>
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

void dfs(TreeNode *root, vector<string> &ans, string s) {
  if (!root) {
    return;
  }
  if (s.empty())
    s += to_string(root->val);
  else
    s += "->" + to_string(root->val);

  if (!root->left && !root->right) {
    ans.push_back(s);
    return;
  }

  dfs(root->left, ans, s);
  dfs(root->right, ans, s);
}
vector<string> binaryTreePaths(TreeNode *root) {

  vector<string> ans;

  dfs(root, ans, "");
  return ans;
}
