#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

bool isOperant(char c) {
  return ((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>= '0' and c<='9'));
}

int prec(char c) {
  if (c == '^') return 3;
  else if(c == '*' or c == '/') return 2;
  else if( c == '+' or c == '-') return 1;
  else return -1;
}

string infixToPostfix(string s) {
  stack<char> st;
  string ans = "";
  for(char it: s) {
    if(isOperant(it)) ans+= it;
    else if(it == '(') st.push(it);
    else if(it == ')') {
      while(st.top() != '(') {
        ans+=st.top(); st.pop();
      }
      st.pop();
    } else {
      while(!st.empty() && prec(it) <=prec(st.top())) {
        ans+=st.top(); st.pop();
      }
      st.push(it);
    }
  }

  while (!st.empty()) {
    ans+=st.top();
    st.pop();
  }
  return ans;
}
