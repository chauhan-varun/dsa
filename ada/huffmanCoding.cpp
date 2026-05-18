#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
  char c;
  int count;
  Node *left;
  Node *right;

  Node(char c, int count) {
    this->c = c;
    this->count = count;
    this->left = this->right = NULL;
  }
};

void printCodes(Node* root, string str){
  if(!root) return;
  if(root->c!='$') cout<< root->c << " : " << str;

  printCodes(root->left, str + '0');
  printCodes(root->right, str+ '1');
}

struct cmp {
  bool operator()(Node *n1, Node *n2) { return n1->count > n2->count; }
};

void huffmanCodes(char data[], int freq[], int n){
  priority_queue<Node *, vector<Node *>, cmp> pq;

  for (int i = 0; i < n; i++) {
    pq.push(new Node(data[i], freq[i]));
  }

  while(pq.size() != 1){
    Node* a = pq.top(); pq.pop();
    Node* b = pq.top(); pq.pop();

    Node* top = new Node('$', a->count + b->count);
    top->left = a;
    top->right = b;
    
    pq.push(top);
  }
  printCodes(pq.top(), "");
}
