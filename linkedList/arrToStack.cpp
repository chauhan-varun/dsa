#include <bits/stdc++.h>
#include <vector>
using namespace std;
class myStack {
private:
  vector<int> arr;
  int idx;
  int size;

public:
  myStack(int n) { size = n; idx = 0; arr.resize(size);}

  bool isEmpty() {
    return (idx == 0);
  }

  bool isFull() {
    return (size == idx);
  }

  void push(int x) {
    if(isFull()) return;
    arr[idx] = x;
    idx++;
  }

  void pop() {
    if(isEmpty()) return;
    idx--;
    arr[idx] = -1;
  }

  int peek() {
    if(isEmpty()) return -1;
    return arr[idx - 1];
  }
};
