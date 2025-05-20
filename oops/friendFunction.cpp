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
    friend void getFriendX(A& a);
};
void getFriendX(A& a) {
    // Access the private member 'x' of class 'A'
    cout << a.x;
}

int main() {
    A obj;
    obj.setX(10);
    getFriendX(obj);

}