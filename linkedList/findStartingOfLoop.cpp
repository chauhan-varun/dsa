#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
  Node(int data, Node *next) : data(data), next(next) {}
};

Node *arrToLL(vector<int> &arr) {
  Node *ans = new Node(arr[0]);
  Node *mover = ans;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return ans;
}

void print(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node* findStart(Node* slow, Node* fast ){
  while (slow!=fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node* findStartingOfLoop(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast==slow) {
      return findStart(head, fast);
    }
  }
  return NULL;
}
