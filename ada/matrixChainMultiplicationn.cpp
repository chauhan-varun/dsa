#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int main() {
  vector<int> arr ={ 5, 4, 6, 2, 7};
  int j, min;
  const int n = 5;
  int m[n][n] = {0};
  int s[n][n] = {0};

  for(int d = 1; d <n -1; d++){
    for(int i=1; i<n-d; i++){
      j = i + d;
      min = INT_MAX;
      for(int k = i; k<j; k++){
        int q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
        if(q<min){
          min = q;
          s[i][j] = k;
        }
      }
      m[i][j] = min;
    }
  }
  cout<<m[1][n-1];
}
