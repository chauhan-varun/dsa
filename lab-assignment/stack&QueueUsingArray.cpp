#include <bits/stdc++.h>
using namespace std;

class Stack {
  int arr[101];

public:
  int size;

  Stack() { size = 0; }

  void push(int x) {
    arr[size] = x;
    size++;
  }

  int pop() {
    if (size == 0)
      return -1;
    size--;
    return arr[size];
  }

  int top() {
    if (size <= 0)
      return -1;
    return arr[size - 1];
  }

  bool empty() { return size == 0; }
};

class Queue {
  int arr[101];
  int left, right;

public:
  Queue() {
    left = -1;
    right = -1;
  }

  int front() {
    if (empty())
      return -1;
    return arr[left];
  }

  void push(int x) {
    if (right == 100) { // overflow protection
      cout << "Queue Overflow\n";
      return;
    }

    if (empty()) {
      left = 0;
      right = 0;
    } else {
      right++;
    }
    arr[right] = x;
  }
  void pop() {
    if (empty())
      return;

    left++;
    if(left > right) left = right = -1;
  }

  bool empty() { return (left == -1 || left > right); }
};
