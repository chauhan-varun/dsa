#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
  int i = 0, j = s.size() - 1;
  while(i<j){
    if(s[i]!=s[j]) return false;
    i++; j--;
  }
  return true;
}
int main() {
  string s =  "dnaman";
  cout<< (int)'0';
}
