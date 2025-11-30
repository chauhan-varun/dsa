#include <bits/stdc++.h>
#include <climits>
#include <utility>
#include <vector>
using namespace std;

void sort(vector<int> &arr) {
  int n = arr.size(); // 412635
  for (int i = 0; i < n; i++) {
    int idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[idx] > arr[j]) {
        idx = j;
      }
    }
    swap(arr[idx], arr[i]);
  }
}

void bsort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    int j = 0;
    while (j < n - i - 1) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
      j++;
    }
  }
}

void isort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int j = i;
    while(j>0 && arr[j-1] >arr[j]){
      swap(arr[j-1] , arr[j]);
      j--;
    }
  }
}
