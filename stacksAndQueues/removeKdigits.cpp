#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string arr, int k) {
  stack<char> st;
  for (int i = 0; i < arr.size(); i++) {
    while (k > 0 && !st.empty() && st.top() > arr[i]) {
      st.pop();
      k--;
    }
    st.push(arr[i]);
  }
  while (k > 0 && !st.empty()) {
    st.pop();
    k--;
  }

  string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  
  int i = 0;
  while (i < ans.size() && ans[i] == '0')
    i++;

  ans = ans.substr(i);

  return ans.empty() ? "0" : ans;
}
