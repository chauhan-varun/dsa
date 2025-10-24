#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int exp) {
    long long ans = 1;
    for (int i = 0; i < exp; i++) {
        ans *= base;
        if (ans > 1e18) return 1e18; // prevent overflow
    }
    return ans;
}

int nthRoot(int r, int x) {
    int low = 1, high = x;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long val = power(mid, r);

        if (val == x)
            return mid;          // perfect rth root found
        else if (val < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // no integer nth root exists
}

int main() {
    cout << nthRoot(3, 27) << endl; // ✅ 3
    cout << nthRoot(3, 9) << endl;  // ✅ -1
    cout << nthRoot(2, 16) << endl; // ✅ 4
}
