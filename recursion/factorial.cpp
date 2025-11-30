#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr, int n) {
  if (n <= 0) {
    return 0;
  }
  return arr[n - 1] + sum(arr, n - 1);
}

int main() {
  
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << "Sum: " << sum(arr, arr.size()) << endl;
}
