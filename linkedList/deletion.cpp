#include<bits/stdc++.h>
using namespace std; 
class Node {
  public:
  int data;
  Node* next;
  
  Node(int data, Node* next): data(data), next(next) {}
  Node(int data): data(data) {}
};

Node* arrToLL(vector<int> &arr) {
  Node* ans = new Node(arr[0]);
  Node* mover = ans;

  for(int i = 1; i<arr.size(); i++ ) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return ans;
}

Node* removeHead(Node* head) {
  if(head == NULL) return NULL;
  Node* temp = head;
  temp = temp->next;
  delete head;
  return temp;
}

Node* removeTail(Node* head) {
  if(head == NULL || head->next == NULL) return NULL;
  
  Node* temp = head;
  while (temp->next->next) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  
  return head;
}

Node* removeK(Node* head, int k) {
  if(head == NULL) return head;

  if(k==1) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  int count = 0;
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    count++;
    if(count == k) {
      prev->next = prev->next->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
  
}

void print(Node* head) {
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" \n";
    temp = temp->next;
  }
}

int main() {
  vector<int> arr = {23,4,4,5,56,3};
  Node* head = arrToLL(arr);
  Node* ans = removeK(head, 3);
  print(ans);
}
