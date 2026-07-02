#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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
int widthOfBinaryTree(TreeNode *root) {
  if(!root)
    return 0;
  
  queue<pair< TreeNode*, long long>> q; 
  long long maxWidth = 0;
  
  q.push({root, 0});
  while(!q.empty()){
    int n = q.size();
    long long minIdx = q.front().second;
    long long  leftMost, rightMost;
    for(int i=0; i<n; i++){
      auto [node, idx] = q.front(); q.pop();
      idx-=minIdx;
      if(i==0)
        leftMost = idx;
      if(i==n-1)
        rightMost = idx;
        
      if(node->left)
        q.push({node->left, 2*idx+1});
      if(node->right)
        q.push({node->right, 2*idx+2});
    }
    maxWidth = max(maxWidth, rightMost - leftMost + 1);
  }
  return maxWidth;
}
