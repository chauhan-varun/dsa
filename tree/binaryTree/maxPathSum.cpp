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
int dfs(TreeNode *root, int &sum) {
  if (!root)
    return 0;

  int ls = max(0, dfs(root->left, sum));
  int rs = max(0, dfs(root->right, sum));

  sum = max(sum, root->val + ls + rs);

  return root->val + max(ls, rs);
}
int maxPathSum(TreeNode *root) {
  int sum = INT_MIN;
  dfs(root, sum);
  return sum;
}
