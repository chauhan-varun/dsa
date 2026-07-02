#include <bits/stdc++.h>
#include <stack>
#include <vector>
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
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack< TreeNode*> st;

    TreeNode* node = root;
    while(true){
      if(node){
        st.push(node);
        node=node->left;
      } else {
        if(st.empty()) break;
        node = st.top(); st.pop();
        ans.push_back(node->val);
        node = node->right;
      }
    }
    return ans;
  }
};
