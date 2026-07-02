#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
  vector<int> heap;

  void heapifyUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        i = parent;
      } else
        break;
    }
  }
  void heapifyDown(int i) {
    int n = heap.size();

    while (true) {
      int largest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      if (left < n && heap[left] > heap[i])
        largest = left;
      if (right < n && heap[right] > heap[i])
        largest = right;
      if (largest == i)
        break;
      swap(heap[largest], heap[i]);
      i = largest;
    }
  }

public:
  void push(int x) {
    heap.push_back(x);
    heapifyUp(heap.size() - 1);
  }

  void pop() {
    if (heap.empty())
      return;
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty())
      heapifyDown(0);
  }

  void heapify(vector<int> &arr, int i, int n) {
    while (i < n) {

      int lg = i;
      int l = 2 * i + 1;
      int r = l + 1;

      if (l < n && arr[l] > arr[lg])
        lg = l;
      if (r < n && arr[r] > arr[lg])
        lg = r;
      if (lg == i)
        break;
      swap(arr[lg], arr[i]);
      i = lg;
    }
  }
  void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, i, n);

    for(int i=n-1; i>0; i--){
      swap(arr[0], arr[i]);
      heapify(arr, 0, i);
    }
  }
  bool empty() { return heap.empty(); }
  int size() { return heap.size(); }
  int top() {
    if (empty())
      return -1;
    return heap[0];
  }
  void print() {
    for (int x : heap) {
      cout << x << " ";
    }
  }
};

int main() {
  Heap h;
  h.push(1);
  h.push(5);
  h.push(9);
  h.push(4);
  h.print();
}
