#include <bits/stdc++.h>
using namespace std;

int expand(string s, int i, int j){
  int c = 0;
  while(i>=0 && j<s.size() && s[i]==s[j]){
    c++;
    i--; j++;
  }
  return c;
}

int countSubstring(string s){
  int ans=0;
  for(int i = 0; i<s.size(); i++){
    ans+=expand(s, i, i);
    ans+=expand(s, i, i+1);
  }
  return ans;
}
