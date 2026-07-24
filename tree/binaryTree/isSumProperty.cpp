#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
bool isSumProperty(Node *root) {
  if (!root || (!root->left && !root->right))
    return true;

  int sum = 0;

  if (root->left)
    sum += root->left->data;
  if (root->right)
    sum += root->right->data;

  return sum == root->data && isSumProperty(root->left) &&
         isSumProperty(root->right);
}
