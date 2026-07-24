#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
vector<int> topView(Node *root) {

  map<int, int> nodes;
  queue<pair<Node *, int>> q;

  q.push({root, 0});
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto it = q.front();
      q.pop();
      Node *node = it.first;
      int l = it.second;

      if (nodes.find(l) == nodes.end()) // remove this condition in the bottom view
        nodes[l] = node->val;
      if (node->left)
        q.push({node->left, l - 1});
      if (node->right)
        q.push({node->right, l + 1});
    }
  }
  vector<int> ans;
  for (auto it : nodes) {
    ans.push_back(it.second);
  }
  return ans;
}
