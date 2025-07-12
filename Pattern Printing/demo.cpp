#include <bits/stdc++.h>
using namespace std;
int NnumbersSum(int n){
    if(n==1) return 1;
    return n*NnumbersSum(n-1);
}
int fib(int n) {
        //your code goes here
        if(n==1 || n==2) return 1;
        return fib(n-1) + fib(n-2);
    }
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
}

