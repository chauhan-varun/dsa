#include <bits/stdc++.h>
using namespace std;
// void rotateArrByK(vector<int> &arr, int k) {
//   int temp[k];
//   int n = arr.size();
//
//   for (int i = 0; i < k; i++) {
//     temp[i] = arr[i];
//   }
//
//   for (int i = k; i < n; i++) {
//     arr[i - k] = arr[i];
//   }
//
//   for (int i = n - k; i < n; i++) { // i = 6
//     arr[i] = temp[i - n + k];
//   }
// }

void rotateArrByK(vector<int> &arr, int k) {
  k %= arr.size();
  int n = arr.size();
  for (int i = 0; i < k; i++) {
    int temp = arr[n - 1];
    for (int j = n - 1; j > 0; j--) {
      arr[j] = arr[j - 1];
    }
    arr[0] = temp;
  }
}
int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  rotateArrByK(arr, k);
  for (auto x : arr) {
    cout << x << " ";
  }
}
