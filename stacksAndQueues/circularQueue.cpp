#include <bits/stdc++.h>
using namespace std;
class Queue {
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue() {
    size = 10001;
    arr = new int[size];
    front = rear = -1;
  }

  bool enqueue(int x) {
    if (isFull())
      return false;

    if (front == -1) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = x;

    return true;
  }

  int dequeue() {
    if (isEmpty())
      return -1;

    int ans = arr[front];
    arr[front] = -1;
    
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front+1) % size;
    }
    return ans;
  }

  bool isEmpty() { return (front == -1 && rear == -1); }

private:
  bool isFull() {
    return ((front == 0 && rear == size - 1) &&
            (rear == (front - 1) % (size - 1)));
  }
};
