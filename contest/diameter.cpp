#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data = data;
      left = right = nullptr;
    }
};

int diameter(Node* root, int &h){
  if(root==NULL){
    h = 0;
    return 0;
  }

  int lh = diameter(root->left, h);
  int rh = diameter(root->right, h);

  h = 1 + max(lh, rh);

  return max({1 + rh + lh, rh, lh});
}
