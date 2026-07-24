#include <bits/stdc++.h>
#include <vector>
using namespace std;
string findOrder(vector<string> &words) {
  vector<vector<int>> adj(26);
  vector<int> inDegree(26, 0);
  vector<bool> exist(26, 0);

  for (auto &s : words) {
    for (auto &c : s) {
      exist[c - 'a'] = 1;
    }
  }

  for (int i = 0; i + 1 < words.size(); i++) {
    string &a = words[i];
    string &b = words[i + 1];
    int len = min(a.size(), b.size());
    int j = 0;
    while (j < len && a[j] == b[j])
      j++;
    if (j == len && a.size() > b.size())
      return "";
    else {
      int u = a[j] - 'a', v = b[j] - 'a';
      adj[u].push_back(v);
      inDegree[v]++;
    }
  }

  queue<int> q;
  int total = 0;
  for (int i = 0; i < 26; i++) {
    if (exist[i]) {
      total++;
      if (!inDegree[i])
        q.push(i);
    }
  }
  string s = "";
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    s += char('a' + node);

    for (int &x : adj[node]) {
      inDegree[x]--;
      if (!inDegree[x])
        q.push(x);
    }
  }
  return (int)s.size() == total ? s : "";
}
