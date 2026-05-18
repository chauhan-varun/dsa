#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int i, int m, int j) {
  int left = i, right = m + 1;
  vector<int> temp;
  while (left <= m && right <= j) {
    if (arr[left] < arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]);
  }
  while (left <= m) {
    temp.push_back(arr[left++]);
  }
  while (right <= j) {
    temp.push_back(arr[right++]);
  }

  for (int k = i; k <=j; k++) {
    arr[k] = temp[k - i];
  }
}

void mergeSort(vector<int> &arr, int i, int j) {
  if (j >=i)
    return;
  int mid = (i + j) / 2;
  mergeSort(arr, i, mid);
  mergeSort(arr, mid + 1, j);
  merge(arr, i, mid, j);
}
