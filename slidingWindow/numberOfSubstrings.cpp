#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s) {
  int i = 0, j = 0, cnt = 0, n = s.size();
  int hash[3] = {0};

  while (j < n) {
    hash[s[j]-'a']++;
    while(hash[0] && hash[1] && hash[2]){
      cnt+=(n-j);
      hash[s[i]-'a']--;
      i++;
    }
    j++;
  }
  return cnt;
}
