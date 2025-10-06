#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' or c == '/')
    return 2;
  else if (c == '-' or c == '+')
    return 1;
  else
    return -1;
}

string inToPost(string s) {

  stack<char> st;
  string ans = "";

  for (char it : s) {
    if ((it >= 'A' and it <= 'Z') or (it >= 'a' and it <= 'z') or
        (it >= '0' and it <= '9')) {
      ans += it;

    } else if (it == '(') {
      st.push('(');

    } else if (it == ')') {
      while (st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();

    } else {
      while (!st.empty() && prec(it) <= prec(st.top())) {
        ans += st.top();
        st.pop();
      }
      st.push(it);
    }
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}
int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  cout << "Postfix expression: " << inToPost(exp);
  return 0;
}
