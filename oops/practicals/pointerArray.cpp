/**
 * Write a C++ program to demonstrate pointer arithmetic by creating an array
of integers and using pointers to traverse and manipulate the array elements.
Implement functions to calculate the sum, average, and maximum value of
the array using pointer arithmetic.
 */

#include<iostream>
#include<climits>
using namespace std;

int sum(int *arr, int n){
    int* ptr = arr;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+= *(ptr+i);
    }
    return sum;
}

int avg(int *arr, int n){
    int sm = sum(arr, n);
    return sm/n;
}

int max(int *arr, int n){
    int* ptr = arr;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        if(mx< *(ptr+i)) mx = *(ptr+i);
    }
    return mx;
}


int main(){
    int n;
    cout<<"Enter the size of arary: ";
    cin>>n;
    cout<<"Enter the elements "<<endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<sum(arr, n)<<endl;
    cout<<avg(arr, n)<<endl;
    cout<<max(arr, n)<<endl;
}