#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int hi) {
  vector<int> temp;
  int count = 0;
  int left = low, right = mid + 1;

  while (left <= mid && right <= hi) {
    if (arr[left] <= arr[right])
      temp.push_back(arr[left++]);
    else {
      count += (mid - left + 1);
      temp.push_back(arr[right++]);
    }
  }

  while (left <= mid)
    temp.push_back(arr[left++]);
  while (right <= hi)
    temp.push_back(arr[right++]);

  for (int i = low; i <= hi; i++)
    arr[i] = temp[i - low];

  return count;
}

int mergeSort(vector<int> &arr, int low, int hi) {
  int count = 0;
  if (low >= hi)
    return count;

  int mid = (low + hi) / 2;
  count += mergeSort(arr, low, mid);
  count += mergeSort(arr, mid + 1, hi);
  count += merge(arr, low, mid, hi);
  return count;
}
