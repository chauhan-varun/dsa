#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  Node *next, *prev;
  int key, value;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    next = prev = nullptr;
  }
};

class LRUCache {
public:
  unordered_map<int, Node *> mpp;
  Node *head, *tail;
  int c;

  LRUCache(int c) {
    this->c = c;
    mpp.clear();
    
    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
  }

  int get(int k) {
    if(mpp.find(k)!=mpp.end()){
      Node* node = mpp[k];
      deleteNode(node);
      addToFront(node);
      return node->value;
    }
    return -1;
  }

  void addToFront(Node *node) {
    Node* temp = head->next;

    node->next = temp;
    node->prev = head;

    temp->prev = node;
    head->next = node;
  }

  void deleteNode(Node* node) {

    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;
  }

  void put(int key, int value) {
    if (mpp.find(key) != mpp.end()) {
      // if key already exist
      Node *node = mpp[key];
      node->value = value;
      
      deleteNode(node);
      addToFront(node);
    } else { // if key not exixt
      if (mpp.size() == c) {
        Node* lru = tail->prev;
        mpp.erase(lru->key);
        deleteNode(lru);
        delete lru;
      }

      Node *node = new Node(key, value);
      mpp[key] = node;
      addToFront(node);
    }
  }
};
