#include<iostream>
using namespace std;

class Bike {
    public:
    static int price; //now its value only be alloted by calling via the class with the scope resolution operator
    int tyreSize;
    int cc;

    Bike (int tyreSize, int cc){    // constructor
        this->tyreSize = tyreSize;
        this->cc = cc;
        // cout<<"constructor called"<<endl;
    }

    // Bike (int ts, int c) : tyreSize(ts), cc(c) {           //intializing list
    // }

    ~Bike(){                            //distructor
        cout<<"distructor Called"<<endl;
    }

    static int increasePrice(){
        price++;
    }
};

int Bike::price = 200000;            // scope resolution operator

int main(){

    Bike hayabuza(23,34);
    // Bike yamaha;
    // yamaha = hayabuza;             //shallow copy
    hayabuza.increasePrice();
    cout<<hayabuza.price<<endl;

    // Bike ktm = hayabuza;         //deep copy
    // Bike tvs(hayabuza);           //deep copy

    Bike tesla(434, 432);
    tesla.increasePrice();
    cout<<tesla.price<<endl;

    
    cout<<hayabuza.tyreSize<<endl;
    cout<<hayabuza.cc<<endl;

}