#include <bits/stdc++.h>
#include <cstddef>
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

Node* findMin(Node* root){
  while(root->left)
    root=root->left;
  return root;
}
Node* deleteNode(Node* root, int key){
  if(root==NULL) return NULL;
  if(key<root->data) deleteNode(root->left, key);
  else if(key>root->data) deleteNode(root->right, key);
  else {
    // 0 child

    if(root->left == NULL && root->right==NULL){
      delete root;
      return NULL;
    } else if(root->left == NULL){
      Node* temp = root->right;
      delete  root;
      return temp;
    } else if(root->right ==NULL){
      Node* temp = root->left;
      delete  root;
      return temp;
    } else {
      Node* temp = findMin(root);

      root->data = temp->data;

      return deleteNode(root->right, temp->data);
    }
  }
  return root;
}
