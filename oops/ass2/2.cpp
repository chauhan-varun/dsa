#include<iostream>
using namespace std;

template <typename T>
T add(T a, T b){
    return a+b;
}
template <typename T>
T sub(T a, T b){
    return a-b;
}
template <typename T>
T mul(T a, T b){
    return a*b;
}
template <typename T>
T divide(T a, T b){
    if(b==0){
        cout<<"denominator can't be zero"<<endl;
        return 0;
    }
    return a/b;
}

template <typename T>
class Calculator {
    private:
    T x, y;

    public:
    Calculator(T a, T b){
        x = a;
        y = b;
    }

    void performOperation(){
        cout<<"addition: "<<add(x, y)<<endl;
        cout<<"substraction: "<<sub(x, y)<<endl;
        cout<<"division: "<<divide(x, y)<<endl;
        cout<<"multiplication: "<<mul(x, y)<<endl;
    }
};

int main(){
    Calculator<int> cal(12, 4);
    cal.performOperation();
cout<<endl;
    Calculator<float> cal2(12.3, 4.3);
    cal2.performOperation();
}