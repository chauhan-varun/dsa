#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class CQueue {
private:
  int front;
  int rear;
  int cap;
  int* arr;

  public:
  CQueue(int cap){
    front = rear = -1;
    this->cap = cap;
    arr = new int[cap];
  }
  
  bool isEmpty() {
    return (front == -1);
  }

  bool isFull() {
    return ((rear + 1) % cap == front);
  }

  void enqueue(int x){
    if(isFull()) return;
    
    if(isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1 ) % cap;
    }
    arr[rear] = x;
  }
  
  void dequeue() {
    if(isEmpty()) return;

    if(front == rear) {
      front = rear = -1;
    } else {
      front = (front+1) % cap;
    }
  }
};
