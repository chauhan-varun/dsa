#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int k, v, cnt;
  Node *next, *prev;

  Node(int k, int v) {
    this->k = k;
    this->v = v;
    next = prev = nullptr;
    cnt = 0;
  }
};

class List {
public:
  Node *head, *tail;
  int size;

  List() {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addToFront(Node *node) {
    Node *temp = head->next;

    node->next = temp;
    node->prev = head;

    head->next = node;
    temp->prev = node;
    size++;
  }

  void deleteNode(Node *node) {

    Node *prev = node->prev;
    Node *next = node->next;

    next->prev = prev;
    prev->next = next;

    size--;
  }
};

class LFUCache {
public:
  unordered_map<int, List *> freqList;
  unordered_map<int, Node *> keyNode;
  int maxSize, minFreq, currSize;

  LFUCache(int c) {
    maxSize = c;
    minFreq = currSize = 0;
  }

  void updateFreqList(Node *node) {
    keyNode.erase(node->k);
    freqList[node->cnt]->deleteNode(node);

    if (node->cnt == minFreq && freqList[node->cnt]->size == 0)
      minFreq++;

    List *newList = new List();

    if (freqList.find(node->cnt + 1) != freqList.end()) {
      newList = freqList[node->cnt + 1];
    }
    node->cnt++;

    newList->addToFront(node);
    freqList[node->cnt] = newList;
    keyNode[node->k] = node;
  }

  int get(int k) {
    if (keyNode.find(k) != keyNode.end()) {
      Node *node = keyNode[k];
      int val = node->v;
      updateFreqList(node);
      return val;
    }
    return -1;
  }

  void put(int k, int v) {
    if (maxSize == 0)
      return;

    if (keyNode.find(k) != keyNode.end()) {
      Node *node = keyNode[k];
      node->v = v;
      updateFreqList(node);
    } else {
      if (currSize == maxSize) {
        List *ls = freqList[minFreq];
        Node *nodeToRemove = ls->tail->prev;

        keyNode.erase(nodeToRemove->k);
        ls->deleteNode(nodeToRemove);
        currSize--;
      }

      currSize++;
      minFreq = 1;

      List *ls;
      if (freqList.find(minFreq) != freqList.end()) {
        ls = freqList[minFreq];
      } else {
        ls = new List();
      }

      Node *node = new Node(k, v);
      node->cnt = 1;

      ls->addToFront(node); 

      freqList[minFreq] = ls;
      keyNode[k] = node;
    }
  }
};
