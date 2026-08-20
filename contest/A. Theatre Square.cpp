#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k;
  cin >> k;
  ll hr = (21 + (k / 60)) % 24;
  ll min = k % 60;

  cout << setfill('0') << setw(2) << hr << ':' << setw(2) << min << '\n';

  return 0;
}
