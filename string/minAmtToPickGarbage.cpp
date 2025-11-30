#include <bits/stdc++.h>
#include <vector>
using namespace std;
int garbageCollection(vector<string> &g, vector<int> &t) {
  int ans = 0, lastG = 0, lastP = 0, lastM = 0;
  for (int i = 0; i < g.size(); i++) {
    string s = g[i];

    for (auto ch : s) {
      ans++;
      if (ch == 'P')
        lastP = i;
      else if (ch == 'G')
        lastG = i;
      else
        lastM = i;
    }
  }

  for(int i = 0; i<lastG; i++) ans+=t[i];
  for(int i =0; i<lastP; i++) ans+=t[i];
  for(int i =0; i<lastM; i++) ans+=t[i];
  
  return ans;
}
