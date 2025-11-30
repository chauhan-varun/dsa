#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;

  Node(int val): val(val), right(NULL), left(NULL) {}
};

void preOrder(Node* head){
  if(!head) return;
  cout<<head->val<<" ";
  preOrder(head->left);
  preOrder(head->right);
}

void postOrder(Node* head){
  if(!head) return;
  postOrder(head->left);
  postOrder(head->right);
  cout<<head->val<<" ";
}

void inOrder(Node* head){
  if(!head) return;
  inOrder(head->left);
  cout<<head->val<<" ";
  inOrder(head->right);
}
int main() {
  //      2
  //    4   6
  //  1  3  5  9
  Node* head = new Node(2);
  head->left = new Node(4);
  head->right = new Node(6);
  head->left->left = new Node(1);
  head->left->right = new Node(3);
  head->right->left = new Node(5);
  head->right->right = new Node(9);
// 2 4 1 3 6 5 9 
// 1 4 3 2 5 6 9 
// 1 3 4 5 9 6 2 
  preOrder(head);
  cout<<endl;
  inOrder(head);
  cout<<endl;
  postOrder(head);
}
