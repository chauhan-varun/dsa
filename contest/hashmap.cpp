#include <bits/stdc++.h>
#include <pthread.h>
#include <utility>
using namespace std;

class HashMap {

private:
  static const int SIZE = 10;
  list<pair<int, int>> table[SIZE];

  int hashFn(int i) { return i % SIZE; }

public:
  void put(int key, int val) {
    int idx = hashFn(key);
    for (auto &p : table[idx]) {
      if (p.first == key) {
        p.second = val;
        return;
      }
    }
    table[idx].push_back({key, val});
  }

  int get(int key) {
    int idx = hashFn(key);

    for (auto &p : table[idx]) {
      if (p.first == key)
        return p.second;
    }
    return -1;
  }

  void erase(int key) {
    int idx = hashFn(key);
    table[idx].remove_if([key](pair<int, int> p) { return p.first == key; });
  }
};
