#include <iostream>
using namespace std;

class A {
    public:
    int a;
};

class B : virtual public A{
    public:
    int b;
};

class C : virtual public A{
    public: 
    int c;
};

class D : public C, public B{
    public:
    int d;
};

int main(){
    D alpha;
    alpha.a = 44;
    cout<<alpha.a;
}