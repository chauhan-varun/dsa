#include <bits/stdc++.h>
using namespace std;

struct Activity {
  public:
    int start;
    int finish;
};

bool static cmp(Activity a, Activity b){
  return a.finish > b.finish;
}

int activitySelection(Activity arr[], int n){
  sort(arr, arr +n, cmp);

  int c = 1;
  int lastFinish = arr[0].finish;

  for(int i =0; i<n; i++){
    if(arr[i].start >= lastFinish){
      c++;
      lastFinish = arr[i].finish;
    }
  }
  return c;
}
