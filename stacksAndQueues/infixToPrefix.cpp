#include <bits/stdc++.h>
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

string reverse(string s) {
  int i = 0;
  int j = s.size() - 1;
  while (i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
  return s;
}

string inToPre(string s) {

  s = reverse(s);
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
      if (it == '^') {
        while (!st.empty() && prec(it) <= prec(st.top())) {
          ans += st.top();
          st.pop();
        }
        st.push(it);
      } else {

        while (!st.empty() && prec(it) < prec(st.top())) {
          ans += st.top();
          st.pop();
        }
        st.push(it);
      }
    }
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return reverse(ans);
}
int main() {
  string exp = "x+y*z/w+u";
  cout << "Infix expression: " << exp << endl;
  cout << "Prefix expression: " << inToPre(exp);
  return 0;
}
