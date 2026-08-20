#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  vector<ll> v;
  v.push_back(n);
  for (int i = n / 2; i >= 1; i--) {
    if (n % i == 0) {
      v.push_back(i);
    }
  }

  sort(v.begin(), v.end());

  for (ll &x : v)
    cout << x << '\n';

  return 0;
}
