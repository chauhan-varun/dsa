#include <bits/stdc++.h>
using namespace std;
string remove(string s) {
  int n = s.size();
  while (true) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[i + 1]) {
        s.erase(i, i + 1);
        count++;
      }
    }
    if (count == 0)
      break;
  }
  return s;
}
int main() {}
