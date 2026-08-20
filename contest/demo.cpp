#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll res = 1;
  res = (res * (a % 100)) % 100;
  res = (res * (b % 100)) % 100;
  res = (res * (c % 100)) % 100;
  res = (res * (d % 100)) % 100;

  cout << setfill('0') << setw(2) << res << '\n';
  return 0;
}
