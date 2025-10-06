#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node* prev;
  Node* next;

  Node(int data): data(data) {}
  Node(int data, Node* prev, Node* next): data(data), prev(prev), next(next) {}

};

void print(Node* head) {
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

Node* reverseDLL(Node* head) {
  if(head == NULL || head->next == NULL) return head;
  Node* curr = head;
  Node* prev = nullptr;
  while (curr != NULL) {
    prev = curr->prev;
    curr->prev = curr->next;
    curr->next = prev;

    curr = curr->prev;
  }
  return prev;
}

Node* arrToDLL(vector<int> &arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i =1; i<arr.size(); i++){
    Node* newNode = new Node(arr[i], temp, nullptr);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}
int main(){
  
  vector<int> arr = {1,2,3,4,5,6};
  Node* head = arrToDLL(arr);
  head = reverseDLL(head);
  print(head);
}
