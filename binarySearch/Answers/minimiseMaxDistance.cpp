#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i = 0; i<n-1; i++){
        pq.push({arr[i+1] - arr[i], i});
    }

    for(int i=1; i<=k; i++){
        auto diff = pq.top(); pq.pop();
        int idx = diff.second;
        howMany[idx]++;
        long double newSectionLen = (arr[idx+1] - arr[idx])/(long double)(howMany[idx] + 1);
        pq.push({newSectionLen, idx});
    }
    return pq.top().first;
}

int numberOfGasStationsRequired(vector<int> &arr, long double k){
    int count = 0;
    for(int i =0; i<arr.size() -1; i++){
        long double diff = arr[i+1] - arr[i];
        if(diff<=k) continue;

        int need = ceill(diff/k) - 1;
        count += need;
    }
    return count;
}
long double minimiseMaxDistance2(vector<int> &arr, int k){
    int n = arr.size();
    long double i = 0;
    long double j = 0;
    for(int i=0; i<n-1; i++){
        j = max((long double)(arr[i+1]- arr[i]), j);
    }

    long double eps = 1e-6;
    while(j - i>eps){
        long double mid = (i+j)/2.0;
        int req = numberOfGasStationsRequired(arr, mid);
        if(req>k) i = mid;
        else j = mid;
    }
    return j;
}

