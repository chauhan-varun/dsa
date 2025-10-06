#include <bits/stdc++.h>
using namespace std;
bool isOperant(char it) {
  if((it>='a' and it<='z') or (it>='A' and it<='Z') or (it>='0' and it<='9')) return true;
  return false;
}
string postToIn(string s) {
  stack<string> st;
  for(char it: s){
    if(isOperant(it)){
      st.push(string(1, it));
    } else {
      string t1 = st.top(); st.pop();
      string t2 = st.top(); st.pop();
      st.push('('+ t2 + it + t1 + ')');
    }
  }
  return st.top();
}
int main() {
  string s = "AB-DE+F*/";
  cout<<postToIn(s);
}
