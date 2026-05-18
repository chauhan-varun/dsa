#include <bits/stdc++.h>
#include <vector>
using namespace std;

int countPrimes(int n) {
  if (n <= 1)
    return 0;
  vector<int> v(n, 1);
  v[0] = v[1] = 0;
  for (int i = 2; i * i < n; i++) {
    if (v[i])
      for (int j = i * i; j < n; j += i)
        v[j] = 0;
  }
  int c = 0;
  for (int x : v)
    c += x;
  return c;
}

vector<int> getSieve(int n) {
  vector<int> v(n, 1);
  if (n > 0)
    v[0] = 0;
  if (n > 1)
    v[1] = 0;

  for (int i = 2; i * i < n; i++) {
    if (v[i]) {

      for (int j = i * i; j < n; j += i)
        v[j] = 0;
    }
  }
  return v;
}

int countPrimes(int l, int r) {
  vector<int> v = getSieve(r+1);
  int c = 0;
  for(int i=1; i<=r; i++)
    v[i]+=v[i-1];

  return v[r] - v[l - 1];
}
int n = 10e6 + 1;
vector<int> spf(n);
void sieve() {
  for(int i=0; i<n; i++)
    spf[i]=i;
  
  for (int i = 2; i * i < n; i++) {
    if (spf[i]==i) {
      for (int j = i * i; j < n; j += i)
        if(spf[j]==j)
          spf[j]=i;
    }
  }
}
vector<int> findPrimeFactors(int n) {
  vector<int> ans;
  while(n>1){
    ans.push_back(spf[n]);
    n/=spf[n];
  }
  return ans;
}
