#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

void getSieve(vector<char> &v, int n) {
  for (int i = 2; i <= n / i; i++) {
    if (v[i]) {
      for (int j = i * i; j <= n; j += i) {
        v[j] = 0;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<char> v(n + 1, 1);
  getSieve(v, n);
  for (int i = 2; i <= n; i++) {
    if (v[i]) {
      cout << i << ' ';
    }
  }

  return 0;
}
