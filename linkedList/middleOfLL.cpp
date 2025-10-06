
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node {
public:
  int data;
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
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int middleOfLL(Node* head){
  Node* slow = head;
  Node* fast = head;

  while (fast != NULL && fast->next !=NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = arrToLL(arr);
  // print(head);
  cout<<middleOfLL(head);
}
