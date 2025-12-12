#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        
        long long first_val, last_val;
        
        if (a[0] == -1 && a[n-1] == -1) {
            first_val = 0;
            last_val = 0;
        } else if (a[0] == -1) {
            first_val = a[n-1];
            last_val = a[n-1];
        } else if (a[n-1] == -1) {
            first_val = a[0];
            last_val = a[0];
        } else {
            first_val = a[0];
            last_val = a[n-1];
        }
        
        if (a[0] == -1) a[0] = first_val;
        if (a[n-1] == -1) a[n-1] = last_val;
        
        for (int i = 1; i < n-1; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        
        long long ans = abs(a[n-1] - a[0]);
        cout << ans << "\n";
        
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n-1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
