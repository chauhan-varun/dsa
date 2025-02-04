#include<iostream>
using namespace std;

int hcf(int diviser, int divident){
    if(diviser==0) return divident;
    hcf(divident%diviser ,diviser);
}

int main(){
    int diviser=27, divident=45;
    cout<<hcf(diviser,divident); //time complexicity is O(log(a+b))
}