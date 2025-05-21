#include <iostream>
using namespace std;

// Function to check if a number is a perfect number
bool isPerfectNumber(int num) {
    int sum = 0;

    // Find all proper divisors and calculate their sum
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // A number is perfect if the sum of its proper divisors equals the number
    return sum == num;
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

for (int i= 0; i<=number; i++){
    if (isPerfectNumber(i)) {
        cout << "Lucky Number" <<i<< endl;
    }// else {
    //     cout << "Not a Lucky Number" << endl;
    // }
}

    return 0;
}