#include <bits/stdc++.h>
using namespace std;

class Queue {
  int start;
  int end;
  int * arr;
  int size;

  public:
  Queue(int size) {
    this->size = size;
    start = end = -1;
    arr = new int[size];
  }

  void pop() {
    if(start == -1) return;

    if(size == end) {
      start = end = -1;
    } else {
      start++;
    }
  }

  void push(int x) {
    if(end == size-1) return;
    arr[++end] = x;
  }

  int top() {
    if(start == -1) return -1;
    return arr[start];
  }
};
