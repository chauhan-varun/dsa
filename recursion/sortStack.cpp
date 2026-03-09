#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int x) {

  if (st.empty() || st.top() <= x) {
    st.push(x);
    return;
  }

  int y = st.top();
  st.pop();
  insert(st, x);
  st.push(y);
}

void sort(stack<int> &st) {
  if (st.empty())
    return;

  int x = st.top();
  st.pop();
  sort(st);
  insert(st, x);
}
