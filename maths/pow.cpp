#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int pow(int a, int b) {
  if (b == 0)
    return 1;

  int half = pow(a, b >> 1);

  if ((b & 1) == 0)
    return half * half;
  else
    return half * half * a;
}

int poww(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;

    a *= a;
    b >>= 1;
  }
  return res;
}
