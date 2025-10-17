#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
  int size;
  int cap;
  int *arr;

  public:
  Stack(int cap) {
    size = 0;
    this->cap = cap;
    arr = new int[cap];
  }

  void push(int x) {
    if(isFull()) return;
    arr[size] = x;
    size++;
  }

  void pop() {
    if(isEmpty()) return;
    arr[--size] = -1;
  }

  int peek() {
    if(isEmpty()) return -1;

    return arr[size-1];
  }

  bool isFull() {
    if (size == cap)
      return true;
    return false;
  }

  bool isEmpty() {
    if(size == 0) return true;
    return false;
  }
};
