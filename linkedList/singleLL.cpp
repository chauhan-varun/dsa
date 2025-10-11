#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next) : data(data), next(next) {}
  Node(int data) : data(data), next(nullptr) {}
};

Node *insertHead(Node *head, int x) {
  return new Node(x, head);
}

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

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

Node* insertTail(Node* head, int x){
  if(head == NULL){
    return new Node(x);
  }
  Node* temp = head;
  while(temp->next) temp = temp->next;
  Node* newNode = new Node(x);
  temp->next = newNode;
  return head;
}

Node* search(Node* head, int x){
  Node* temp = head;
  while(temp){
    if(temp->data == x) return temp;
    temp = temp->next;
  }
  return NULL;
}


int main() {
  vector<int> arr = {1,3,4,5,6,7};
  Node *head = arrToLL(arr);
  // printLL(head);
  Node *nn = search(head, 3);
  cout<<nn->next;
  // printLL(nn);
}
