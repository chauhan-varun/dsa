#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int pivot(vector<int> &arr, int i, int j) {
  int low = i, hi = j;
  int pivot = arr[i];
  while (i < j) {
    while (i < hi && arr[i] <= pivot) {
      i++;
    }
    while (j > low && arr[j] >= pivot) {
      j--;
    }
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int i, int j) {
  if (j <= i)
    return;
  int p = pivot(arr, i, j);
  quickSort(arr, i, p - 1);
  quickSort(arr, p + 1, j);
}
