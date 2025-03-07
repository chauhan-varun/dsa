#include<iostream>
using namespace std;

class Vehicle {
    public:
    int a;

    virtual void show(){
        cout<<"vehicle's class"<<endl;
    }
};

class TwoWheeler : public Vehicle {
    public:
    int b;

    virtual void show(){
        cout<<"TwoWheeler's class"<<endl;
    }
};

class Bike : public TwoWheeler {
    public: 
    int c;

    void show(){
        cout<<"bike's Class"<<endl;
    }
};

int main(){

    Vehicle * a;            //compilor POV - its vehicle type
    a = new TwoWheeler;     //runtime POV - its TwoWheeler type
    a->show();              //compile time binding (no virtual)
                             //run time binding (virtual)
    TwoWheeler b;
    Vehicle *x;            //Vptr vitual pointer     vtable virtual Table  
    x = &b;
    x->show();

    Vehicle * y;
    y = new Bike;
    y->show();

    TwoWheeler yamaha;
    yamaha.show();
}