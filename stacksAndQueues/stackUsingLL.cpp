#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
  int data;
  Node *next;

public:
  Node(int data) : data(data) {}
  Node(int data, Node *next) : data(data), next(next) {}
};

class Stack {

  public:
  Node* top = NULL;
  int size = 0;
  
  
  void push(int x) {
    Node *temp = new Node(x, top);
    top = temp;
    size++;
  }

  void pop() {
    if(top == NULL) return;
    Node* temp = top;
    temp = temp->next;
    delete top;
    size--;
  }

  int Size() {
    return size;
  }
};
int main() {}
