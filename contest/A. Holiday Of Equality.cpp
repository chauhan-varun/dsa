#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  ll maxi = 0;
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
    maxi = max(maxi, v[i]);
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ans += (maxi - v[i]);
  }
  cout << ans << endl;
  return 0;
}
