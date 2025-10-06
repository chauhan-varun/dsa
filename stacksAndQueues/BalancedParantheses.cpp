#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool balancedParantheses(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
      st.push(s[i]);
    } else {
      if (st.empty())
        return false;
      char ch = st.top();
      st.pop();
      if (ch == '{' and s[i] == '}' or ch == '(' and s[i] == ')' or
          ch == '[' && s[i] == ']')
        continue;
      else
        return false;
    }
  }
  return st.empty();
}

int main() {
  string s = "(){()[]}";
  cout << balancedParantheses(s);
}
