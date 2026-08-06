#include<iostream>
using namespace std;
int main() {
    int x= 5;
    int arr[] = {2,3,4,2,4,8};
    int n = sizeof(arr[0]);
    for(int i = 0 ; i<n ; i++) {
        if(arr[i] == x) {
            for(int j = 1 ; j< n - 1 ; j++) {
                arr[j] = arr[j + 1];

            }
            break;
        }
    }
    for(auto x: arr)
    cout<<x << " ";
}