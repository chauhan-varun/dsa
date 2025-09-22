#include<bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std; 

class Node {
  public:
  int data;
  Node* next;
  Node* back;

  Node(int data, Node* next, Node* back): data(data), next(next), back(back) {}
  Node(int data): data(data) {}
};

Node* arrToDLL(vector<int> &arr) {
  Node* head = new Node(arr[0]);
  Node* back = head;
  for(int i =1; i<arr.size(); i++ ) {
    Node* newNode = new Node(arr[i], nullptr, back);
    back->next = newNode;
    back = newNode;
  }
  return head;
}
void printDLL(Node* head) {
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
Node* removeHead(Node* head) {
  if(head == NULL || head->next == NULL) return NULL;

  Node* ans = head;
  ans= ans->next;
  delete head;
  
  head->next = nullptr;
  ans->back = nullptr;
  
  return ans;
}

Node* removeTail(Node* head){
  if(head == NULL || head->next == NULL) return NULL;
  Node* tail = head;
  while(tail->next){
    tail = tail->next;
  }
  Node* temp = tail->back;
  delete tail;
  tail->back = nullptr;
  temp->next = nullptr;
  return head;
}

Node* removeK(Node* head,int k) {
  if(!head) return NULL;
  if(k==1) {
    Node* temp = head->next;
    if (temp) {
      temp->back = NULL;
    }
    delete head;
    return temp;
  }

  int count = 0;
  Node* temp = head;
  while(temp) {
    count++;
    if(count ==k){
      Node* prev = temp->back;
      Node* next = temp->next;
      
      prev->next = next;
      if(next) next->back = prev;

      temp->back = nullptr;
      temp->next = nullptr;
      delete temp;
      break;
    }
    temp = temp->next;
  }
  return head;
}

int main() {
  vector<int> arr = {2,3,5,6,7,8};
  Node* head = arrToDLL(arr);
  head = removeK(head, 6);
  printDLL(head);
}
