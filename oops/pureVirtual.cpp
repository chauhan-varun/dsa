#include <iostream>
using namespace std;

class Parent {
    public:
    int a;

    virtual void func() = 0;  //pure virtual function (mandatory to child class to override it)
};

class Child : public Parent {
    public:
    int b;

    void func(){
        cout<<"it must should be override"<<endl;
    }
    
};

int main(){
    Child c;
    c.b = 4;
    cout<<c.b<<endl;
    c.func();
}