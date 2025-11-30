#include <bits/stdc++.h>
using namespace std;
int numberOfBeams(vector<string> &b) {
  int count = 0, n = b.size();
  for (int i = 0; i < n; i++) {
    while (b[i].find('1') != string::npos) {
      int idx = b[i].find('1');
      for (int j = i + 1; j < n; j++) {
        if (idx < b[j].find('1'))
          count++;
      }
      b[i].replace(idx, idx, "0");
    }
  }
  return count;
}
