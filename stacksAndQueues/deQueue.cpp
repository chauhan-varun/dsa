#include <bits/stdc++.h>
using namespace std;

class Dequeue {
  int* arr;
  int front;
  int rear;
  int size;

  public:
  Dequeue(){
    size = 10001;
    front = rear = -1;
    arr = new int[size];
  }

  bool push_front(int x){
    if(isFull()) return false;
    
    if(front == -1) {
      front = rear = 0;
    }
    else if(front == 0 && rear !=size-1) {
      front = size - 1;
    } else {
      front--;
    }
    arr[front] = x;
    return true;
  }

  bool push_back(int x){
    if(isFull()) return false;
    
    if(front == -1) {
      front = rear = 0;
    } else {
      rear = (rear+1) % size;
    }
    arr[rear] = x;
    return true;
  }
  
  int pop_front(){
    if(isEmpty()) return -1;

    int ans = arr[front];
    arr[front] = -1;
    
    if(front == rear) {
      front = rear = -1;
    } else {
      front = (front +1 ) % size;
    }
    return ans;
  }
  
  int pop_back() {
    if(isEmpty()) return -1;

    int ans = arr[rear];
    arr[rear] = -1;

    if(rear == front) {
      front = rear = -1;
    } else if(rear == 0) {
      rear = size -1;
    } else {
      rear--;
    }

    return ans;
  }

  int getFront() {
    if(isEmpty()) return -1;
    return arr[front];
  }

  int getRear() {
    if(isEmpty()) return -1;
    return arr[rear];
  }

  bool isEmpty(){
    return (front == -1);
  }

  bool isFull(){
      return (rear + 1) % size == front;
  }
};
