#include <bits/stdc++.h>
#include <new>
#include <vector>
using namespace std;
class Node {
public:
  int val;
  Node* next;

  Node(int val): val(val), next(NULL) {}
  Node(int val, Node* next): val(val), next(next) {}
};

Node* arrToLL(vector<int> &arr){
  int n = arr.size();
  Node* head = new Node(arr[0]);
  Node* temp = head;

  for(int i = 1; i<n; i++){
    Node* node = new Node(arr[i]);
    temp->next = node;
    temp = node;
  }
  return head;
}
void print(Node* head){
  Node* temp = head;
  while (temp) {
    cout<<temp->val<<" ";
    temp = temp->next;
  }
}

Node* insertHead(Node* head, int x){
  if(!head) return new Node(x);
  return new Node(x, head);
}
Node* insertTail(Node* head, int x){
  if(!head) return new Node(x);
  
  Node* temp = head;
  while(temp->next){
    temp = temp->next;
  }
  temp->next = new Node(x);
  return head;
}

Node* insertAtK(Node* head, int k, int x){
  if(k == 1 || !head) return insertHead(head, x);
  int c = 1;
  Node* temp = head;
  while(temp){
    c++;
    if(c==k){
      Node* next = temp->next;
      temp->next = new Node(x, next);
      break;
    }
    temp = temp->next;
  }
  return head;
}

Node* deleteHead(Node* head) {
  if(!head || !head->next) return NULL;

  Node* newHead = head->next;
  delete head;
  return newHead;
}

Node* deleteValue(Node* head, int x){
  if(!head ) return NULL;
  if(head->val ==x) {
    Node* newHead = head->next;
    delete head;
    return newHead;
  }

  Node* temp = head;
  Node* prev = NULL;
  while(temp){
    if(x == temp->val){
      Node* node = temp;
      prev->next = temp->next;
      delete node;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
int main() {
  vector<int> arr = {1,2,3,4,5,6};
  Node* head = arrToLL(arr);
  head = insertAtK(head, 3, 7);
  print(head);
}
