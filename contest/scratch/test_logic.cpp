#include <iostream>
#include <string>
#include <vector>

using namespace std;

char solve(long long n) {
    long long len = 1;
    long long cnt = 9;
    long long st = 1;
    while (n > len * cnt) {
        n -= len * cnt;
        len++;
        cnt *= 10;
        st *= 10;
    }
    long long num = st + (n - 1) / len;
    string s = to_string(num);
    return s[(n - 1) % len];
}

int main() {
    for (int i = 1; i <= 15; i++) {
        cout << "N=" << i << ": " << solve(i) << endl;
    }
    return 0;
}
