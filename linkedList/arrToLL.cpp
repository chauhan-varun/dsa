#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;

  Node(int data, Node* next): data(data), next(next) {}

  Node(int data): data(data) {}
};

Node* arrToll(vector<int> &arr) {
  Node* ans = new Node(arr[0]);
  Node* mover = ans;

  for(int i = 1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return ans;
}

int main() {
  vector<int> arr = {2,4,5,2,1,4};
  Node* head = arrToll(arr);
  Node* temp = head;

  int count = 0;
  while(temp) {
    cout<< temp->data << " \n";
    count++;
    temp = temp->next;
  }
  cout<<"Count: "<<count;
  
}
