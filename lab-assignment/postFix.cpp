#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isOperant(char c) {
  return (c>='0' && c<='9');
}
int postFix(string s) {
  stack<int> st;

  for (char c : s) {
    if (isOperant(c)) {
      st.push(c - '0');
    } else {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();

      switch (c) {
      case '+':
        st.push(a + b);
        break;
      case '-':
        st.push(a - b);
        break;
      case '*':
        st.push(a * b);
        break;
      case '/':
        st.push(a / b);
        break;
      }
    }
  }
  return st.top();
}
