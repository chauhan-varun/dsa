#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &a, vector<int> &b) {
  stack<int> st;
  int n = a.size() - 1, m = b.size() - 1;
  unordered_map<int, int> mpp;

  for (int i = n; i >= 0; i--) {
    while (!st.empty() && st.top() <= b[i]) {
      st.pop();
    }

    if (st.empty()) {
      mpp[b[i]] = -1;
    } else {
      mpp[b[i]] = st.top();
    }

    st.push(b[i]);
  }

  vector<int> res;
  for (int x : a) {
    res.push_back(mpp[x]);
  }

  return res;
}
