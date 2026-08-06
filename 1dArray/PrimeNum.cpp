#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    cout << "Prime numbers: ";
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) cout << arr[i] << " ";
    }
    return 0;
}
