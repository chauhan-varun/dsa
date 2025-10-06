#include <bits/stdc++.h>
using namespace std;
class Stack {
  int size;
  int * arr;
  int top;

  Stack(int size) {
    top = -1;
    this->size = size;
    arr = new int[size];
  }

public: 
  void push(int x) {
    top++;
    arr[top] = x;
  }

  void pop() {
    top--;
  }

  int Top() {
    return arr[top];
  }

  int Size() {
    return top+1;
  }
  
};
