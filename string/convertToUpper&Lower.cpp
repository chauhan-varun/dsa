#include <bits/stdc++.h>
using namespace std;
void converToUpper(string &str){
  for(char &c: str) {
    if(c>='a' && c<='z'){
      c = c - 'a' + 'A';
    }
  }
}
void converToLower(string &str){
  for(char &c: str) {
    if(c>='A' && c<='Z'){
      c = c + 'a' - 'A';
    }
  }
}

int main() {
  string str = "Varun";
  converToLower(str);
  cout<< str;
}
