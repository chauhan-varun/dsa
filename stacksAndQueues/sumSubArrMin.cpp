#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

vector<int> nse(vector<int> &arr) {
  stack<int> st;
  int n = arr.size();
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i])
      st.pop();

    ans[i] = st.empty() ? n : st.top();
    
    st.push(i);
  }
  return ans;
}

vector<int> psee(vector<int> &arr) {
  stack<int> st;
  int n = arr.size();
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i])
      st.pop();

    ans[i] = st.empty() ? -1: st.top();
    
    st.push(i);
  }
  return ans;
}

int sumSubarrayMins(vector<int> &arr) {
  const int MOD = (int)(1e9 + 7);
  int n = arr.size();
  long long ans = 0;
  vector<int> ps = psee(arr);
  vector<int> ns = nse(arr);
  for (int i = 0; i < n; i++) {
    long long left = i - ps[i];
    long long right = ns[i] - i;
    ans = (ans + left * right * arr[i]) % MOD;
  }
  return (int)ans;
}
