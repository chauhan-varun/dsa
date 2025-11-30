#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool canWePlace(vector<int> &arr, int dist, int k){
    int count = 1, last = arr[0];
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] - last >=dist){
            count++;
            last = arr[i];
        }
        if (count>=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
        
    sort(stalls.begin(), stalls.end());
    int i = 1, j = stalls[stalls.size()-1] - stalls[0];

    while(i<=j){
        int mid = (i+j)/2;
        if(canWePlace(stalls, mid, k)) i = mid + 1;
        else j = mid -1;
    }
    return (j);
}
