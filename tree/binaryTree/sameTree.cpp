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

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;

  if (!p || !q)
    return false;

  if (q->val != p->val)
    return false;

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
