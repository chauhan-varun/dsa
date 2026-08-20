#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "YES\n";
    return 0;
  }
  if (n % 2 == 0) {
    cout <<"NO\n";
    return 0;
  }
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
