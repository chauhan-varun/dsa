#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll one, two, three;
  while (n > 0) {
    one = n % 10;
    two = n % 100;
    three = n % 1000;
    if (one == 1) {
      n /= 10;
    } else if (two == 14) {
      n /= 100;
    } else if (three == 144) {
      n /= 1000;
    } else {
      break;
    }
  }
  cout << ((n > 0) ? "NO\n" : "YES\n");
  return 0;
}
