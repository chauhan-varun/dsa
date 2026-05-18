#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &arr) {
  int n = arr.size();
  vector<int> st;

  for (int i = 0; i < n; i++) {
    if (arr[i] > 0)
      st.push_back(arr[i]);
    else {
      while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i]))
        st.pop_back();

      if (!st.empty() && st.back() == abs(arr[i]))
        st.pop_back();
      else if (st.empty() || st.back() < 0)
        st.push_back(arr[i]);
    }
  }
  return st;
}
