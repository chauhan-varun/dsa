#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    int i = n - 1;
    while (i >= 0) {
      while (!st.empty() && st.top() < arr[i])
        st.pop();

      if (st.empty())
        nge[i] = -1;
      else
        nge[i] = st.top();

      st.push(arr[i--]);
    }
    return nge;
  }
};
