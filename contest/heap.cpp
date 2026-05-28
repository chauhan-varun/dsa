#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
  int arr[100];
  int size;
  Heap() { size = 0; }

public:
  void insert(int x) {
    size++;
    int idx = size;
    arr[idx] = x;

    while (idx > 1) {
      int pIdx = idx / 2;
      if (arr[pIdx] < arr[idx]) {
        swap(arr[pIdx], arr[idx]);
      } else
        return;
    }
  }

  void pop() {
    if (size < 1)
      return;
    int i = 1;
    arr[1] = arr[size--];

    while (true) {
      int l = 2 * i, r = l + 1, lg = i;
      if (l <= size && arr[l] > arr[lg])
        lg = l;
      if (r <= size && arr[r] > arr[lg])
        lg = r;
      if (lg != i) {
        swap(arr[lg], arr[i]);
        i = lg;
      } else
        return;
    }
  }
};

void heapify(vector<int> &arr, int idx) {
  int l = idx * 2, r = l + 1, lg = idx, n = arr.size();

  if (l <= n && arr[l] < arr[lg])
    lg = l;
  if (r <= n && arr[r] < arr[lg])
    lg = r;
  if (lg != idx) {
    swap(arr[lg], arr[idx]);
    idx = lg;
  }
}

void heapSort(vector<int> &arr) {
  int n = arr.size();
  while (n != 1) {
    swap(arr[1], arr[n--]);
    heapify(arr, 1);
  }
}
