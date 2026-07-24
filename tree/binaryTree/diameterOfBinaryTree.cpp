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
int dia(TreeNode *root, int &h) {
  if (!root)
    return 0;

  int lh = dia(root->left, h);
  int rh = dia(root->right, h);

  h = max(h, lh + rh);

  return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root) {
  int h = 0;
  dia(root, h);
  return h;
}
