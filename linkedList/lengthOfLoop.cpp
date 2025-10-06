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

int lengthOfLoop(Node *head) {
  map<Node*, int> mpp;
  int count = 0;
  Node *temp = head;
  while (temp) {
    if (mpp.find(temp) != mpp.end()) {
      return count - mpp[temp];
    }
    count++;
    mpp[temp] = count;
    temp = temp->next;
  }
  return 0;
}
int findLen(Node* start, Node* end) {
  int counter = 1;
  start = start->next;
  while(start!=end) {
    start = start->next;
    counter++;
  }
  return counter;
}
int lengthOFLoop(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while(fast!= NULL && fast->next != NULL){
    slow= slow->next;
    fast = fast->next->next;
    if(slow==fast) return findLen(slow, fast);
  }
  return 0;
}
