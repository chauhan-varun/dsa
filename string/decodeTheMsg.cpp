#include <bits/stdc++.h>
using namespace std;
string decodeMsg(string k, string m){
  char temp = 'a';
  string ans = "";
  char mpp[1000] = {0};

  for(auto ch: k){
    if(ch != ' ' && mpp[ch]!=0)
    mpp[ch] = temp++;
  }

  for(auto ch: m){
    if(ch == ' ') ans+=' ';
    else ans+=mpp[ch];
  }
  return ans;
}
