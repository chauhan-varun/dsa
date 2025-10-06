#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int x){
  set<vector<int>> ans;
  int n = arr.size();

  for(int i = 0; i<n; i++){
    for(int j = i+1; j<n; j++){
      set<long long> st;
      for(int k = j+1; k<n; k++){
        long long sum  = x;
        sum-= arr[i];
        sum-=arr[j];
        sum-=arr[k];
        if(st.find(sum)!=st.end()){
          vector<int> temp = {arr[i], arr[j], arr[k], (int)sum};
          sort(temp.begin(), temp.end());
          ans.insert(temp);
        }
        st.insert(arr[k]);
      }
    }
  }

  vector<vector<int>> a(ans.begin(), ans.end());
  return a;
}

vector<vector<int>> fourSUm(vector<int> &arr, int x){
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;

  for(int i = 0; i<n; i++){
    if(i>0 && arr[i] == arr[i-1]) continue;
    for(int j = i+1; j<n; j++){
      if(j> i+1 && arr[j] == arr[j-1]) continue;
      int k = j+1;
      int l = n -1;
      while(k<l){
        long long sum = arr[i];
        sum+=arr[j];
        sum+=arr[k];
        sum+=arr[l];
        if(sum<x) k++;
        else if(sum>x) l--;
        else{
          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp);
          k++; l--;

          while(k<l && arr[k] == arr[k-1]) k++;
          while(k<l && arr[l] == arr[l+1]) l--;
        }
      }
    }
  }

  return ans;

}
