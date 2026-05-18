#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

int extraction(int n) {
  int res = 0;
  while (n > 0) {
    res = res * 10 + n % 10;
    n /= 10;
  }
  return res;
}
bool armstrongNumber(int n) {
  int res = 0;
  int m = n;
  while (m > 0) {
    res += pow(m % 10, 3);
    m /= 10;
  }
  return res == n;
}

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
int gcd(int a, int b) {
  int n = (min(a, b));
  for (int i = n; i >= 1; i--) {
    if (i % a == 0 && i % b == 0)
      return i;
  }
  return 1;
}

vector<int> printAllPrimeFactors(int n) {
  vector<int> ans;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  }
  if(n!=1) ans.push_back(n);
  return ans;
}


int main() { cout << extraction(23345); }
