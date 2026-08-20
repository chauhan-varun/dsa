#include <bits/stdc++.h>
using namespace std;
#define MOD 100'000'007
#define RADIX 26
#define ll long long int

class Solution {
private:
  ll hashFn(const string &s, ll m) {
    ll hashValue = 0, factor = 1;
    for (ll i = m - 1; i >= 0; i--) {
      hashValue = (hashValue + (s[i] - 'a') * factor) % MOD;
      factor = (factor * RADIX) % MOD;
    }
    return hashValue;
  }

  bool rabinKarp(const string &text, const string &pattern) {
    ll n = text.size(), m = pattern.size();
    if (m == 0 || m > n)
      return false;

    ll hashPattern = hashFn(pattern, m);
    ll hashWindow = hashFn(text, m);

    ll MAX_VALUE = 1;
    for (int i = 0; i < m; i++) {
      MAX_VALUE = (MAX_VALUE * RADIX) % MOD;
    }

    for (ll i = 0; i <= n - m; i++) {
      if (hashPattern == hashWindow && text.compare(i, m, pattern) == 0)
        return true;

      if (i < n - m) {
        hashWindow =
            ((hashWindow * RADIX) % MOD - ((text[i] - 'a') * MAX_VALUE) % MOD +
             (text[i + m] - 'a') + MOD) %
            MOD;
      }
    }
    return false;
  }
};
