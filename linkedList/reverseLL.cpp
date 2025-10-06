#include <bits/stdc++.h>
using namespace std;
class Node { public: int data;
  Node *next;

  Node(int val) : data(val), next(nullptr){}
  Node(int data, Node *next ) : data(data), next(next){}
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


void print(Node *head) {
  cout << endl;
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node* reverseLL(Node* head) {
  Node* temp = head;
  Node* prev = nullptr;

  while(temp){
    Node* next = temp->next;
    temp->next = prev;
    
    prev = temp;
    temp = next;
  }
  return prev;
}

Node* reverse(Node* head) {
  if(head == NULL || head->next == NULL) {
    return head;
  }
  Node* newHead = reverse(head->next);
  Node* front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

int main() {
  vector<int> arr = {1,23,4,5,6};
  Node* head = arrToLL(arr);
  head = reverse(head);
  print(head);
}
