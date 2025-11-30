#include <bits/stdc++.h>
using namespace std;
string reverse(string str) {
  int i = 0, j = str.size() - 1;
  while (i < j) {
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
    i++; j--;
  }
  return str;
}
int main() {
  string str;
  cout << "Enter a string: ";
  getline(cin, str);
  str = reverse(str);
  cout << str;
}
