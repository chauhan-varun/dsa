#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) : data(data), left(NULL), right(NULL) {}
  Node(int data, Node *left, Node *right)
      : data(data), left(left), right(right) {}
};

vector<vector<int>> preInPost(Node *root) {
  if(!root) return {};
  vector<vector<int>> ans;
  vector<int> pre, in, post;
  stack<pair<Node *, int>> st;

  st.push({root, 1});
  while (!st.empty()) {
    auto it = st.top();
    st.pop();
    if (it.second == 1) {
      pre.push_back(it.first->data);
      it.second = 2;
      st.push(it);
      if (it.first->left)
        st.push({it.first->left, 1});
      
    } else if (it.second == 2) {
      in.push_back(it.first->data);
      it.second = 3;
      st.push(it);
      if (it.first->right)
        st.push({it.first->right, 1});
      
    } else {
      post.push_back(it.first->data);
    }
  }
  ans.push_back(pre);
  ans.push_back(in);
  ans.push_back(post);

  return ans;
}

int main() {}
