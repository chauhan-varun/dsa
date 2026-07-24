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
  vector<int> postorder(TreeNode *root) {
    if (!root)
      return {};
    stack<TreeNode *> st;
    stack<int> ans;
    vector<int> res;

    st.push(root);
    while (!st.empty()) {
      auto node = st.top();
      st.pop();
      ans.push(node->val);
      if (node->left)
        st.push(node->left);
      if (node->right)
        st.push(node->right);
    }

    while (!ans.empty()) {
      res.push_back(ans.top());
      ans.pop();
    }
    return res;
  }
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root)
      return {};
    stack<TreeNode *> st;
    vector<int> ans;

    TreeNode *node = root;
    while (node || !st.empty()) {
      if (node) {
        st.push(node);
        node = node->left;
      } else {
        TreeNode* temp = st.top()->right;
        if(temp)
          node = temp;
        else {
          temp = st.top();
          st.pop();
          ans.push_back(temp->val);
          while(!st.empty() && temp == st.top()->right){
            temp = st.top(); st.pop();
            ans.push_back(temp->val);
          }
        }
      }
    }
    return ans;
  }
};
