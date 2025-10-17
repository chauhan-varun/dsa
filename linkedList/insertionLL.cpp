#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}
  Node(int data, Node *next) : data(data), next(next) {}
};

Node *arrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = temp->next;
  }
  return head;
}

void print(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node *insertHead(Node *head, int x) {
  if (head == NULL) {
    return new Node(x);
  }

  return new Node(x, head);
}

Node *insertTail(Node *head, int x) {
  if (!head)
    return new Node(x);

  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  Node *newTail = new Node(x);
  temp->next = newTail;
  return head;
}

Node *insertAtK(Node *head, int k, int x) {
  if (!head)
    return new Node(x);

  int i = 2;
  Node *temp = head;
  while (i < k) {
    i++;
    temp = temp->next;
  }

  Node *newNode = new Node(x, temp->next);
  temp->next = newNode;
  return head;
}

int main() {
  vector<int> arr = {12, 2, 3, 3, 4, 6};
  Node *head = arrToLL(arr);
  head = insertAtK(head, 4, 4);
  print(head);
}
