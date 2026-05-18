#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> pse(vector<int> &arr) {
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i])
      st.pop();
    ans[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return ans;
}
vector<int> nse(vector<int> &arr) {
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i])
      st.pop();
    ans[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return ans;
}

int largestRectangleArea(vector<int> &arr) {
  int area = INT_MIN, n = arr.size();
  vector<int> ps = pse(arr);
  vector<int> ns = nse(arr);
  for (int i = 0; i < n; i++) {
    area = max(area, arr[i] * (ns[i] - ps[i] - 1));
  }
  return area;
}

int maximalRectangle(vector<vector<char>> &arr) {
  int n = arr.size(), m = arr[0].size();
  int area = INT_MIN;

  vector<int> hist(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(arr[i][j]=='1') hist[j]++;
      else hist[j]=0;
    }
    area = max(largestRectangleArea(hist), area);
  }
  return area;
}
