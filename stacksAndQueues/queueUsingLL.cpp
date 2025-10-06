#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;

  Node(int data) : data(data) {}
  Node(int data, Node *next) : data(data), next(next) {}
};

class Queue {
public:
  Node *head;
  Node *tail;
  int size;

  Queue() {
    head = tail = NULL;
    size = 0;
  }

  void push(int x) {
    Node *temp = new Node(x);
    if (head) {
      head = tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }
    size++;
  }

  void pop() {
    if (head == NULL)
      return;

    Node *temp = head;
    head = head->next;
    delete temp;
    size--;

    if (head)
      tail = nullptr;
  }
};
int main() {}
