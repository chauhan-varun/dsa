#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string intToBit(int n) {
  if (n == 0)
    return "0";
  string s = "";
  while (n > 0) {
    s += (n % 2) + '0';
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}

string intToBitOptimize(int n) {
  if (n == 0)
    return "0";
  string s = "";
  while (n > 0) {
    s += (n & 1) + '0';
    n >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}

int bitToInt(string s) {

  int res = 0;
  int pow = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    int bit = s[i] - '0';
    res += bit * (1 << pow);
    pow++;
  }
  return res;
}

int bitToBin(string s){
  int res = 0;
  for(char c: s){
    res = res * 2 + (c-'0');
  }
  return res;
}

int main() {
  cout << intToBitOptimize(13)<<endl;
  cout << bitToBin("1101");
}
