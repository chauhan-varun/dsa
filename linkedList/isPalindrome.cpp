#include <bits/stdc++.h>
#include <cstddef>
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

Node *reverse(Node *head) {
  if(head == NULL || head->next == NULL ) return head;
  Node* newHead = reverse(head);
  Node* front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

bool isPalindrome(Node *head) {
  if(head==NULL || head->next == NULL) return true;
  Node *temp = head;

  Node *slow = head;
  Node *fast = head;

  while (fast->next->next != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *newHead = reverse(slow->next);
  Node *tempo = newHead;
  while (tempo) {
    if (temp->data != tempo->data) {
      reverse(newHead);
      return false;
    }
    tempo = tempo->next;
    temp = temp->next;
  }
  reverse(newHead);
  return true;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 3, 2, 1};
  Node *head = arrToLL(arr);
  print(head);
  cout << endl << isPalindrome(head)<<endl;
  print(head);
}
