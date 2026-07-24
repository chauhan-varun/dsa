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

int rightHeight(TreeNode *root) {
  TreeNode *curr = root;
  int h = 0;
  while (curr) {
    h++;
    curr = curr->right;
  }
  return h;
}
int leftHeight(TreeNode *root) {
  TreeNode *curr = root;
  int h = 0;
  while (curr) {
    h++;
    curr = curr->left;
  }
  return h;
}

int countNodes(TreeNode *root) {
  if (!root)
    return 0;

  int lh = leftHeight(root->left);
  int rh = rightHeight(root->right);

  if (lh == rh)
    return (1 << (lh + 1)) - 1;

  return 1 + countNodes(root->left) + countNodes(root->right);
}
