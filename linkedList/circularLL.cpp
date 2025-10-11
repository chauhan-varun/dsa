#include <bits/stdc++.h>
#include <vector>
using namespace std;
class CLL {
private:
  int front, size, end, cap;
  vector<int> arr;
  
public: 
  CLL(int cap){
    this->cap = cap;
    size = 0;
    front = end = -1;
    arr.resize(size);
  }

  bool isEmpty() {
    return (front == -1 || end == -1);
  }

  bool isFull() {
    return (front = ((end + 1) % size));
  }

  void enqueue(int x){
    if(isFull()) return;
    if(isEmpty()) {
      front = end = 0;
    } else{
      end = (end + 1) % cap;
    }
    arr[end] = x;
    size++;
  }

  void dequeue(){
    if(isEmpty()) return;
    if(front == end){
      front = end = -1;
    } else {
      front = (front + 1) % cap;
    }
    size--;
  }

  void display() {
    if(isEmpty()) return;
    int i = front;
    while(true){
      cout<<arr[i]<<" ";
      if(i== end) break;
      i = (i+1) % cap;
    }
    cout<<"\n";
  }
};

int main() {
  
}
