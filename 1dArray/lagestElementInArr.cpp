#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
  vector<int> arr = {6,4,23,7,3,2,3};
      int max = INT_MIN;

  for(int i = 0; i<arr.size(); i++){
    if(max<arr[i]) max = arr[i];
  }
  cout<<max;
}
