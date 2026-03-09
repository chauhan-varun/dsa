#include <bits/stdc++.h>
#include <vector>
using namespace std;
void subsets(vector<int>& arr, int i, vector<vector<int>> &ans, vector<int> &temp){
    ans.push_back(temp);
    for(int j=i; j<arr.size(); j++){
        if(j!=i && arr[j-1]==arr[j]) continue;
        temp.push_back(arr[i]);
        subsets(arr, i+1, ans, temp);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    subsets(arr, 0, ans, temp);
    return ans;
}
