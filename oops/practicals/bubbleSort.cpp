/**
 * Implement a C++ program that sorts an array of integers using the bubble
sort algorithm. The program should allow the user to input the array
elements, then use a function to sort the array in ascending order. Display
the sorted array as the output
 */

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    bubbleSort(arr, n);
    printArr(arr, n);

}