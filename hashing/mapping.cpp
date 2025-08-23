#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    cin >> n; 
    int arr[n];

    for(int &i : arr) {
        cin >> i;
    }

    map<int, int> mpp;
    
    const int size = 100;
    int hash[size] = {0};
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--) {
        int query;
        cin >> query;
        cout << query << " " << mpp[query] << endl;
    }
    return 0;
}
