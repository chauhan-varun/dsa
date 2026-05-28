#include <bits/stdc++.h>
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

bool isValid(Node *root, int mini, int maxi) {
  if (root == NULL)
    return true;
  if (root->data <= mini || root->data >= maxi)
    return false;

  return (isValid(root->left, mini, root->data) &&
          isValid(root->right, root->data, maxi));
}
