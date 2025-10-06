#include <bits/stdc++.h>
using namespace std;
bool isOperant(char it) {
  if((it>='a' and it<='z') or (it>='A' and it<='Z') or (it>='0' and it<='9')) return true;
  return false;
}
string preToIn(string s) {
  stack<string> st;
  for(int i = s.size() -1; i>=0; i--){
    char it = s[i];
    if(isOperant(it)){
      st.push(string(1, it));
    } else {
      string t1 = st.top(); st.pop();
      string t2 = st.top(); st.pop();
      st.push('('+ t1 + it + t2 + ')');
    }
  }
  return st.top();
}
int main() {
  string s = "*+PQ-MN";
  cout<<preToIn(s);
}
