#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Nth apple (Digit in a sequence)
 * Given an integer N, return the Nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 * 
 * Approach:
 * 1. Find the length of the number that contains the Nth digit (1-digit numbers, 2-digit numbers, etc.).
 * 2. Find the actual number.
 * 3. Find the digit within that number.
 */

int main() {
    long long n;

    if (!(cin >> n)) return 0;

    long long len = 1;    // Number of digits in the current range (1, 2, 3...)
    long long count = 9;  // Total numbers in the current range (9, 90, 900...)
    long long start = 1;  // Starting number of the current range (1, 10, 100...)

    // Step 1: Find the range (length of the number)
    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    // Step 2: Find the actual number containing the Nth digit
    // (n-1) because n is now the relative position within the current length range
    long long num = start + (n - 1) / len;

    // Step 3: Find the digit within that number
    string s = to_string(num);
    cout << s[(n - 1) % len] << endl;

    return 0;
}
