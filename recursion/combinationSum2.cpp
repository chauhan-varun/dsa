#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void comb(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int i, int x){
    if(x==0){
        ans.push_back(temp);
        return;
    }

    for(int j = i; j<arr.size(); j++){
        if(j>i && arr[j]==arr[j-1]) continue;
        if(arr[j]>x) break;
        temp.push_back(arr[j]);
        comb(arr, temp, ans, j+1, x-arr[j]);
        temp.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& arr, int x) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    comb(arr, temp, ans, 0, x);
    return ans;
}
