#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};
vector<Node *> findPreSuc(Node *root, int key) {
  Node *pred = NULL, *succ = NULL;

  while (root) {
    if (key >= root->data) {
      pred = root;
      root = root->right;
    } else {
      succ = root;
      root = root->left;
    }
  }
  return {pred, succ};
}
