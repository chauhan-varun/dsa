#include<bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;
class Node {
  public:
  int data;
  Node* next;
  
  Node(int data, Node* next): data(data), next(next) {}
  Node(int data): data(data) {}
};

void print(Node* head ) {
  Node* temp = head;
  while (temp) {
    cout<<temp->data<<" \n";
    temp = temp->next;
  }
}

Node* insertHead(Node* head, int x){
  Node* temp = head;
  return new Node(x, head);
}

Node* insertTail(Node* head, int x) {
  Node* temp = head;
  while(temp->next) {
    temp = temp->next;
  }
  
  temp->next = new Node(x);
  return temp;
}

Node* insertK(Node* head, int x, int k) {
  Node* temp = head;

  if(temp == NULL){
    if(k == 1) 
      return new Node(x);
    else return NULL;
  }
  
  if(k==1) {
    Node* newHead = new Node(x, head);
    return newHead;
  }
  
  int count = 0;
  while(temp) {
    count++;
    if(count == k-1) {
      Node* newNode = new Node(x, temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }

  return head;
}

Node* arrToLL(vector<int> &arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i =1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
int main() {
  vector<int> arr = {2,3,5,6,7,3};
  Node* head = arrToLL(arr);
  head = insertK(head, 4, 3);
  print(head);
}
