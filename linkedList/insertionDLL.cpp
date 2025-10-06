#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
  Node(int data, Node *next, Node *prev) : data(data), next(next), prev(prev) {}
};

Node *arrToDLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *temp = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *newNode = new Node(arr[i], nullptr, temp);
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
  Node *newHead = new Node(x, head, nullptr);
  head->prev = newHead;
  return newHead;
}

Node *insertTail(Node *head, int x) {
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  Node *newTail = new Node(x, nullptr, temp);
  
  temp->next = newTail;
  return head;
}

Node* insertAtK(Node* head, int x , int k){
  if(k==1) return insertHead(head, x);
  Node* temp = head;
  int count = 0;
  while(temp){
    count++;
    if(count == k){
      Node* prev = temp->prev;
      Node* newNode = new Node(x, temp, prev);
      prev->next = newNode;
      temp->prev = newNode;
    }
    temp = temp->next;
  }
  return head;
}
int main() {
  vector<int> arr = {2, 3, 4, 6, 45, 6};
  Node *head = arrToDLL(arr);
  head = insertAtK(head, 1, 3);
  print(head);
}
