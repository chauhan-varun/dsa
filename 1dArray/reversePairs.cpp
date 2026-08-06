#include <bits/stdc++.h>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int st, int mid, int end) {
  vector<int> temp;
  int left = st, right = mid + 1;
  while (left <= mid && right <= end) {
    if (arr[left] < arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]);
  }
  while (left <= mid)
    temp.push_back(arr[left++]);
  while (right <= end)
    temp.push_back(arr[right++]);
  for (int i = st; i <= end; i++) {
    arr[i] = temp[i - st];
  }
}

int countPairs(vector<int> &arr, int st, int mid, int end) {
  int count = 0, right = mid + 1;
  for (int i = st; i <= mid; i++) {
    while (right <= end && (long long)arr[i] > (long long)2 * arr[right])
      right++;
    count += (right - (mid + 1));
  }
  return count;
}
int mergeSort(vector<int> &arr, int st, int end) {
  int count = 0;
  if (st >= end)
    return count;
  int mid = (st + end) / 2;
  count += mergeSort(arr, st, mid);
  count += mergeSort(arr, mid + 1, end);
  count += countPairs(arr, st, mid, end);
  merge(arr, st, mid, end);
  return count;
}
int reversePairs(vector<int> &nums) {
  int n = nums.size();
  return mergeSort(nums, 0, n - 1);
}
