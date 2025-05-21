#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; // If divisible by any number other than 1 and itself, not prime
        }
    }
    return true;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int primeCount = 0, nonPrimeCount = 0;

    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (isPrime(num)) {
            primeCount++;
        } else {
            nonPrimeCount++;
        }
    }

    cout << "Number of prime numbers: " << primeCount << endl;
    cout << "Number of non-prime numbers: " << nonPrimeCount << endl;

    return 0;
}