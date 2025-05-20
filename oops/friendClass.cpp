#include<iostream>
using namespace std;

class A {
    // Declare a private member variable 'x'
    private:
        int x;
    // Declare a public member function 'setX' to set the value of 'x'
    public:
        void setX(int val) {
            x = val;
        }
    // Declare a friend class 'B'
    friend class B;
};

class B {
    // Declare a public member function 'getX' to get the value of 'x'
    public:
        int getX(A& a) {
            return a.x; // Access the private member 'x' of class 'A'
        }
};

int main() {
    // Declare a class named 'A'
    B b; // Create an object of class 'B'
    A a; // Create an object of class 'A'
    a.setX(10); // Set the value of 'x' using the 'setX' function of class 'A'
    cout<<b.getX(a); // Call the 'getX' function of class 'B' to get the value of 'x'
    // Output the value of 'x' using the 'getX' function of class 'B'
}
