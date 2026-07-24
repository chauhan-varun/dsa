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
bool isMirror(TreeNode* a, TreeNode* b){
  if(!a && !b)
    return true;
  
  if(!a || !b)
    return false;

  if(a->val != b->val)
    return false;

  return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(TreeNode *root) {
  return isMirror(root->left, root->right);
}
