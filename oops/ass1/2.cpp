/*
Overload a function to find the area of Square, Rectangle and Circle in C++.
*/
#include<iostream>
using namespace std;

class AreaCalculator {
    public:
        void area(int side) {
            cout << "Area of Square: " << side * side << endl;
        }
    
        void area(int length, int breadth) {
            cout << "Area of Rectangle: " << length * breadth << endl;
        }
    
        void area(double radius) {
            cout << "Area of Circle: " << 3.14 * radius * radius << endl;
        }
    };

int main(){

    AreaCalculator a;
    a.area(5);
    a.area(2,3);
    a.area(3.5);
    
}

    

