#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *prev;
  Node(int val) : val(val), next(NULL), prev(NULL) {}
};

class Stack {
  Node *node;
  int size;

public:
  Stack() {
    node = NULL;
    size = 0;
  }

  void push(int x) {
    Node *newNode = new Node(x);

    if (node != NULL) {
      node->next = newNode;
      newNode->prev = node;
    }
    node = newNode;
    size++;
  }

  void pop() {
    if (isEmpty())
      return;

    Node *newNode = node;
    node = node->prev;

    if (node)
      node->next = NULL;
    delete newNode;
    size--;
  }

  int top() {
    if (isEmpty())
      return -1;
    return node->val;
  }

  bool isEmpty() { return size == 0; }
};

class Queue {
  Node *front;
  Node *end;
  int size;

public:
  Queue() {
    front = NULL;
    end = NULL;
    size = 0;
  }

  void push(int x) {
    Node *node = new Node(x);
    if (isEmpty()) {
      front = end = node;
    } else {
      end->next = node;
      end = node;
    }

    size++;
  }

  void pop() {
    if (isEmpty())
      return;
    Node *node = front;
    front = front->next;
    delete node;
    size--;
    if (size == 0)
      front = end = NULL;
  }

  int frnt() {
    if (isEmpty())
      return -1;

    return front->val;
  }

  bool isEmpty() { return (front == NULL); }
};
