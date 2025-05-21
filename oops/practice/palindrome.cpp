#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    // Reverse the number
    while(num>0){
        int digit = num%10;
        reversedNum = reversedNum*10 + digit;
        num/=10;
    }

    // Check if the original number is equal to the reversed number
    return originalNum == reversedNum;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> numbers(n);
    vector<char> results(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Check each number and store 'Y' or 'N' in the results array
    for (int i = 0; i < n; ++i) {
        if (isPalindrome(numbers[i])) {
            results[i] = 'Y';
        } else {
            results[i] = 'N';
        }
    }

    // Output the results
    cout << "Palindrome results: ";
    for (char result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}