#include <bits/stdc++.h>
using namespace std;
struct Item {
  int value;
  int wt;
};

class Solution {
public:
  bool static cmp(Item i1, Item i2){
    return (((double)i1.value/i1.wt) > ((double)i2.value/i2.wt));
  }
  double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    
    double val = 0.0;
    for(int i = 0; i<n; i++){
      if(arr[i].wt<=W){
        W-=arr[i].wt;
        val+=arr[i].value;
      } else {
        val+=((double)arr[i].value/arr[i].wt*W);
        break;
      }
    }
    return val;
  }
};
