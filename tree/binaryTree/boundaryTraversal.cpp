#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

bool isLeaf(Node *root) { return !root->left && !root->right; }

void leftView(Node *root, vector<int> &ans) {
  Node *node = root;

  while (node) {
    if (!isLeaf(node))
      ans.push_back(node->data);

    if (node->left)
      node = node->left;
    else
      node = node->right;
  }
}

void rightView(Node *root, vector<int> &ans) {
  if (!root)
    return;

  Node *node = root;
  vector<int> temp;

  while (node) {
    if (!isLeaf(node))
      temp.push_back(node->data);

    if (node->right)
      node = node->right;
    else
      node = node->left;
  }
  for (int i = temp.size() - 1; i >= 0; i--)
    ans.push_back(temp[i]);
}

void leafs(Node* root, vector<int> &ans){
  if(!root)
    return;
  
  if(isLeaf(root)){
    ans.push_back(root->data);
    return;
  }

  leafs(root->left, ans);
  leafs(root->right, ans);
}
vector<int> boundaryTraversal(Node *root) {
  if(!root)
    return {};
  
  vector<int> ans;
  
  if(!isLeaf(root))
        ans.push_back(root->data);
  
  leftView(root->left, ans);
  leafs(root, ans);
  rightView(root->right, ans);
  return ans;
}
