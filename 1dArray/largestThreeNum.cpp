#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[7];
    cout << "Enter array of 7 elements: ";
    for(int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for(int i = 0; i < 7; i++) {
        if(arr[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2) {
            max3 = max2;
            max2 = arr[i];
        }
        else if(arr[i] > max3) {
            max3 = arr[i];
        }
    }
    
    cout << "The three largest unique elements are: " << max1 << ", " << max2 << ", " << max3 << endl;
    
    return 0;
}		