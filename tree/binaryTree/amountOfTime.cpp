#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int amountOfTime(TreeNode *root, int start) {
  queue<TreeNode *> q;
  unordered_map<TreeNode *, TreeNode *> parent;
  TreeNode *startNode = nullptr;

  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      q.pop();
      if (node->val == start) {
        startNode = node;
        break;
      }

      if (node->left) {
        parent[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parent[node->right] = node;
        q.push(node->right);
      }
    }
    if (startNode)
      break;
  }
  q = queue<TreeNode *>();
  unordered_map<int, bool> vis;
  q.push(startNode);
  vis[startNode->val] = true;
  int time = -1;
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      q.pop();

      if (node->left && !vis[node->left->val]) {
        vis[node->left->val] = 1;
        q.push(node->left);
      }

      if (node->right && !vis[node->right->val]) {
        vis[node->right->val] = 1;
        q.push(node->right);
      }

      if (parent.find(node) != parent.end() && !vis[parent[node]->val]) {
        vis[parent[node]->val] = 1;
        q.push(parent[node]);
      }
    }
    time++;
  }
  return time;
}
