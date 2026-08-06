#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 5;
  int arr[] = {2, 4, 5, 1, 6, 3, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      for (int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
      }
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << arr[i] << " ";
  }
}
