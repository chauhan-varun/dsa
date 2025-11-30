#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Heap {
public:
  int arr[101];
  int size;

  Heap() { size = 0; }

  void insert(int val) {
    size++;
    int idx = size;
    arr[idx] = val;

    while (idx > 1) {
      int pIdx = idx / 2;

      if (arr[pIdx] < arr[idx]) {
        swap(arr[pIdx], arr[idx]);
        idx = pIdx;
      } else
        return;
    }
  }

  void pop() {
    if (size < 1)
      return;

    arr[1] = arr[size];
    size--;
    int i = 1;

    while (true) {
      int left = i * 2;
      int right = i * 2 + 1;
      int largest = i;
      if (left <= size && arr[largest] < arr[left]) {
        largest = left;
      }
      if (right <= size && arr[largest] < arr[right]) {
        largest = right;
      }

      if (largest != i) {
        swap(arr[i], arr[largest]);
        i = largest;
      } else
        return;
    }

  }
};

int main() {
  Heap h;
  for (int i = 1; i <= 10; i++) {
    h.insert(i);
  }
  h.pop();

  for (int i = 1; i <= h.size; i++) {
    cout << h.arr[i] << " ";
  }
}
