#include <bits/stdc++.h>
#include <queue>
#include <vector>
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

vector<vector<int>> lot(Node* root){
  vector<vector<int>> ans;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    vector<int> level;
    for(int i=0; i<n; i++){
      Node* node = q.front();
      q.pop();
      level.push_back(node->data);
      if(node->left) q.push(node->left);
      if(node->right)  q.push(node->right);
    }
    ans.push_back(level);
  }
  return ans;
}
