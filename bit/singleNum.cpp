#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &arr) {
  long long xorr = 0;
  for (int x : arr)
    xorr ^= x;

  int bit = (xorr & (xorr - 1)) ^ xorr;

  int a = 0, b = 0;
  for (int x : arr) {
    if ((x & bit) == 0)
      a ^= x;
    else
      b ^= x;
  }
  return {a, b};
}
