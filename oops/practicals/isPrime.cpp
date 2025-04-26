/**
 * Create a C++ program that checks if a given number is a prime number. The
program should prompt the user to enter a number, then use control
structures and functions to determine if the number is prime. Display an
appropriate message indicating the result.
 */

#include<iostream>
using namespace std;

bool isPrime(int a){
    if(a<=1) return false;
    for(int i = 2; i*i<=a; i++){
        if(a%i==0) return false;
    }

    return true;
}
int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    isPrime(a) ? cout<<a<<" is Prime" : cout<<a<<" is'nt prime";
}