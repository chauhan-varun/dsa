#include <bits/stdc++.h>
using namespace std;

class TrieNode {
private:
  TrieNode *children[26]{};
  bool isEnd = false;

public:
  bool hasChild(char c) { return children[c - 'a'] != nullptr; }

  void addChild(char c, TrieNode *node) { children[c - 'a'] = node; }

  TrieNode *getChild(char c) { return children[c - 'a']; }

  void setEnd() { isEnd = true; }

  bool hasEnd() { return isEnd; }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  void insert(string word) {
    TrieNode *curr = root;
    for (char c : word) {
      if (!curr->hasChild(c))
        curr->addChild(c, new TrieNode());
      curr = curr->getChild(c);
    }
    curr->setEnd();
  }

  bool checkPrefixExist(string &word) {
    TrieNode *curr = root;
    for (char c : word) {
      if (!curr->hasChild(c))
        return 0;

      curr = curr->getChild(c);

      if (!curr->hasEnd())
        return 0;
    }

    return 1;
  }
};

class Solution {
public:
  string longestValidWord(vector<string> &words) {
    Trie trie;
    for (string &w : words)
      trie.insert(w);

    string ans = "";
    for (string &w : words) {
      if (trie.checkPrefixExist(w) &&
          ((ans.size() < w.size()) || (ans.size() == w.size() && w < ans)))
        ans = w;
    }
    return ans;
  }
};
