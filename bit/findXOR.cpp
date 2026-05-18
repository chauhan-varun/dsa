#include <bits/stdc++.h>
using namespace std;
int xorr(int n){
  if(n%4==1) return 1;
  else if(n%4==2) return n+1;
  else if(n%4==3) return 0;
  else return n;
}
int findXOR(int l, int r) {
  return xorr(l-1) ^ xorr(r);
}
