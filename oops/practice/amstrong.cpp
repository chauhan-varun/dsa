#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    while (num > 0) {
        digits++;
        num /= 10;
    }

    num = originalNum;

    // Calculate the sum of the digits raised to the power of the number of digits
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }

    return sum == originalNum;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int armstrongCount = 0, nonArmstrongCount = 0;

    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (isArmstrong(num)) {
            armstrongCount++;
        } else {
            nonArmstrongCount++;
        }
    }

    cout << "Number of Armstrong numbers: " << armstrongCount << endl;
    cout << "Number of non-Armstrong numbers: " << nonArmstrongCount << endl;

    return 0;
}