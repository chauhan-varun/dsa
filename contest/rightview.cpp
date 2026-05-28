#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};

void rightview(Node *root, int level, vector<int> &ans) {
  if (root == NULL)
    return;

  if (level == ans.size())
    ans.push_back(root->data);
  if (root->right)
    rightview(root->right, level + 1, ans);
  if (root->left)
    rightview(root->left, level + 1, ans);
}
