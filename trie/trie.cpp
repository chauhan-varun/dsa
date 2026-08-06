#include <string>
using namespace std;

class TrieNode {
private:
  TrieNode *children[26]{};

public:
  int prefixCount = 0;
  int endCount = 0;

  bool hasChild(char c) const { return children[c - 'a'] != nullptr; }

  void setChild(char c, TrieNode *node) { children[c - 'a'] = node; }

  TrieNode *getChild(char c) const { return children[c - 'a']; }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  void insert(const string &word) {
    TrieNode *current = root;

    for (char c : word) {
      if (!current->hasChild(c)) {
        current->setChild(c, new TrieNode());
      }

      current = current->getChild(c);
      current->prefixCount++;
    }

    current->endCount++;
  }

  bool search(const string &word) const {
    TrieNode *current = root;

    for (char c : word) {
      if (!current->hasChild(c)) {
        return false;
      }

      current = current->getChild(c);
    }

    return current->endCount > 0;
  }

  bool startsWith(const string &prefix) const {
    TrieNode *current = root;

    for (char c : prefix) {
      if (!current->hasChild(c)) {
        return false;
      }

      current = current->getChild(c);
    }

    return current->prefixCount > 0;
  }

  int countWordsEqualTo(const string &word) const {
    TrieNode *current = root;

    for (char c : word) {
      if (!current->hasChild(c)) {
        return 0;
      }

      current = current->getChild(c);
    }

    return current->endCount;
  }

  int countWordsStartingWith(const string &prefix) const {
    TrieNode *current = root;

    for (char c : prefix) {
      if (!current->hasChild(c)) {
        return 0;
      }

      current = current->getChild(c);
    }

    return current->prefixCount;
  }

  void erase(const string &word) {
    if (countWordsEqualTo(word) == 0) {
      return;
    }

    TrieNode *current = root;

    for (char c : word) {
      current = current->getChild(c);
      current->prefixCount--;
    }

    current->endCount--;
  }
};
