#include<iostream>
using namespace std;

class Bike {
    public: 
    int price;
    int weight;

    Bike(int p, int w) : price(p), weight(w){}             //constructor overloading
    Bike(int p) : price(p), weight(100){}
    Bike() : price(100000), weight(150){}
};

int calculateArea(int l, int b){                           //function overloading 
    return l*b;
}

float calculateArea(int r){
    return 3.14* r*r;
}

int main(){

    Bike ktm;
    cout<<ktm.price<<endl;

    Bike yamaha(200000);
    cout<<yamaha.price<<endl;

    cout<<calculateArea(20, 10)<<endl;
    cout<<calculateArea(22)<<endl;

}