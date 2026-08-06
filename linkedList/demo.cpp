#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  Node *y = new Node(arr[0], nullptr);
  cout << y << " " << y->data;
}
