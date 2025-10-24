#include <bits/stdc++.h>
using namespace std;
int findSqrt(int x) {
  int i = 1, j = x, ans = 1;
  while (i <= j) {
    int mid = (i + j  ) / 2;
    
    if((mid * mid) <=x){
      ans = mid;
       i = mid + 1;
    }
    else
      j = mid - 1; 
  }
  return ans;
}

int main() {
  cout<<findSqrt(28);
}
