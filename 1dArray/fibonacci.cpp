#include <iostream>
int fibo(int n) {
  if (n <= 1)
    return n;
  return fibo(n - 1) + fibo(n - 2);
}
using namespace std;
int main() {
  int n , a = 1, b = 1, sum = 0;
  cin>>n;
  // for (int i = 1; i <= n - 2; i++) {
  //   sum = a + b;
  //   a = b;
  //   b = sum;
  // }
  // cout << b;
  cout<<fibo(n);
  return 0;
}
