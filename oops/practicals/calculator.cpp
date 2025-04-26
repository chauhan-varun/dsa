/**
 * Implement a simple calculator in C++ that can perform basic arithmetic
operations such as addition, subtraction, multiplication, and division. The
program should prompt the user to enter two numbers and an operator, then
display the result. Use appropriate data types and control structures to handle
the calculations and validate user inputs.
 */

#include<iostream>
using namespace std;

class Calculator {
    private:
    int a;
    int b;

    public:
    void setNum(){
        cout<<"Enter the first number: ";
        cin>>a;
        cout<<"Enter the second number: ";
        cin>>b;
    }
    void getNum(){
        cout<<"First Number "<<a<<endl;
        cout<<"Second Number "<<b<<endl;
    }

    int add(){
        return a+b;
    }
    int sub(){
        return a-b;
    }
    int div(){
        if(b==0) {
            cout<<"Denominator can't be zero";
            return 0;
        }
        return a/b;
    }
    int mul(){
        return a*b;
    }

};
int main(){

    Calculator cal;
    cal.setNum();

    cout << "Addition: " << cal.add() << endl;
    cout << "Subtraction: " << cal.sub() << endl;
    cout << "Division: " << cal.div() << endl;
    cout << "Multiplication: " << cal.mul() << endl;
}