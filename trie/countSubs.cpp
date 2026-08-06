#include <bits/stdc++.h>
using namespace std;

class TrieNode {
private:
  TrieNode *children[26]{};

public:
  bool hasChild(char c) { return children[c - 'a'] != nullptr; }

  void addChild(char c, TrieNode *node) { children[c - 'a'] = node; }

  TrieNode *getChild(char c) { return children[c - 'a']; }
};
class Solution {
public:
  int countSubs(string &s) {
    int cnt = 0;
    TrieNode *root = new TrieNode();
    int n = s.size();
    for (int i = 0; i < n; i++) {
      TrieNode *curr = root;
      for (int j = i; j < n; j++) {
        if (!curr->hasChild(s[j])) {
          cnt++;
          curr->addChild(s[j], new TrieNode());
        }
        curr = curr->getChild(s[j]);
      }
    }
    return cnt + 1;
  }
};
