#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool possible(const vector<int> &arr, int d, int cap) {
    int days = 1;              // start with day 1
    int curr = 0;              // current weight loaded on the ship today

    for (int w : arr) {
        if (curr + w <= cap) { // can we add this package without exceeding cap?
            curr += w;         // yes → add to current day's load
        } else {
            days++;            // no → need a new day
            curr = w;          // start loading this package on the new day
            if (days > d)      // if we already need more than d days
                return false;  // capacity too small
        }
    }

    return days <= d;          // return true if fits within d days
}

int shipWithinDays(vector<int> &arr, int d) {
    int i = *max_element(arr.begin(), arr.end());
    int j = 0;
    for(int x: arr) j+=x;

    while(i<=j){
        int mid = (i+j)/2;
        if(possible(arr, d, mid)) j = mid -1;
        else i = mid + 1;
    }
    return i;
}
