#include<bits/stdc++.h>
#include <vector>
using namespace std;

void combination(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, int x, int i){
    if(i == arr.size()){
        if(x == 0){
            ans.push_back(temp);
        }
        return;
    }

    if(arr[i] <= x) {
        temp.push_back(arr[i]);
        combination(arr, ans, temp, x-arr[i], i);
        temp.pop_back();
    }

    combination(arr, ans, temp, x, i+1);
}

