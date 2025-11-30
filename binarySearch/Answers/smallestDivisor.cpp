#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;
int divi(vector<int>& arr, int d){
    int ans = 0;
    for(int x: arr){
        ans+=ceil((double)x/d);
    }
    return ans;
}
int smallestDivisor(vector<int> &arr, int y) {
    int j = *max_element(arr.begin(), arr.end());
    int i = 1;
    while (i<=j) {
        int mid = (i+j)/2;
        if(divi(arr, mid)<=y) j = mid - 1;
        else i = mid + 1;
    }
    return i;
}
