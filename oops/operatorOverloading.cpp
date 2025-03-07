#include<iostream>
using namespace std;

class ComplexNumber {  
    public:
    int real;
    int imaginary;


    friend ComplexNumber operator +(ComplexNumber &c1, ComplexNumber &c2)
};

ComplexNumber operator + (ComplexNumber &c1, ComplexNumber &c2){
    ComplexNumber c3;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    return c3;
}


int main(){
     
    ComplexNumber c1;
    c1.real = 3;
    c1.imaginary = 4;

    ComplexNumber c2;
    c2.real = 5;
    c2.imaginary = 8;


    ComplexNumber c3 = c1 + c2;
    // c3 = c1 + c2;
    cout << "Real Number: " << c3.real << " Imaginary Number: " << c3.imaginary << endl;
    return 0;
}