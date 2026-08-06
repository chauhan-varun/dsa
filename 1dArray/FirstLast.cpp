#include <iostream>
using namespace std;

int firstLastSum(int n) {
    int last = n % 10;
    while (n >= 10) {
        n /= 10;
    }
    int first = n;
    return first + last;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        cout << "Sum of first and last digit of " << arr[i] 
             << " = " << firstLastSum(arr[i]) << endl;
    }
    return 0;
}
