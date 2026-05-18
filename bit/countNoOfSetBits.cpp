#include <bits/stdc++.h>
using namespace std;

int countNoOfBits(long long n) {
  int count = 0;
  for (int i = 0; i < 63; i++) { // 31
    if (n & (1LL << i))
      count++;
  }
  return count;
}
int countNoOfBits2(long long n) {
  int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}

int lastSetBit(long long n) {
  for (int i = 0; i < 63; i++) {
    if (n & (1LL << i))
      return i;
  }
  return -1;
}

int unsetLastSetBit(long long n) { return n & (n - 1); }

int main() { cout << unsetLastSetBit(1024); }
