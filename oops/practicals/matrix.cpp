/**
 * Write a C++ program to perform basic matrix operations such as addition,
 * subtraction, and multiplication. Use two-dimensional arrays to represent the
 * matrices and implement functions for each operation. Ensure the program
 * handles matrices of appropriate sizes and displays the results accurately
 */
#include<iostream>
using namespace std;

int add(int arr1[], int a, int b, int arr2, int x, int y){

}

int main(){
    int r1, c1, r2, c2;
    int arr1[r1][c1];
    int arr2[r2][c2];

    cout<<"Enter the number of row or column of matrix 1: ";
    cin>>r1>>c1;
    cout<<"Enter the elements of the matrix 1: ";
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>arr1[r1][c1];
        }
    }

    cout<<"Enter the number of row or column of matrix 2: ";
    cin>>r2>>c2;
    cout<<"Enter the elements of the matrix: ";
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin>>arr2[r2][c2];
        }
    }

    if(r1==r2 && c1==c2){
        // addArray(arr1, arr2, r1, c1);
    } else {
        cout<<"Addition and Subtraction not possible (dimension mismatch)\n";
    }

    if(c1==r1){
        multiplyMatrix(arr1, arr2, )
    }


}