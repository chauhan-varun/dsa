#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> findTwoSum(vector<int>& arr, int target) {
    unordered_map<int, int> mp; // faster than map
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[arr[i]] = i;
    }
    return {}; // return empty if no pair found
}

string findtwoSum(vector<int> a, int x){
  int i=0, j =a.size()-1;
  sort(a.begin(), a.end());
  while(i<j){
    int sum = a[i]+a[j];
    if(sum<x){
      i++;
    } else if(sum>x) {
      j--;
    } else {
      return "True";
    }
  }
  return "False";
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    vector<int> result = findTwoSum(arr, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Values: " << arr[result[0]] << ", " << arr[result[1]] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}
