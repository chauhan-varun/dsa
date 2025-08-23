#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Covers all lowercase letters a-z (ASCII 97 to 122)
    const int size = 26; // 122 + 1 to include 'z'
    int hash[size] = {0};

    for (char c : s) {
        hash[c - 'a']++;
    }

    int numberOfQuery;
    cin >> numberOfQuery;

    while (numberOfQuery--) {
        char query;
        cin >> query; // expects 0 for 'a', 1 for 'b', ..., 25 for 'z'
        cout << query << " " << hash[query-'a'] << endl;
    }

    return 0;
}

