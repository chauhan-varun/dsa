#include <iostream>
#include <string>
using namespace std;
/*
class MyString
{
private:
    string str;

public:
    MyString(string s = "")
    {
        str = s;
    }

    void display(){
        cout<<str;
    }

    friend MyString operator+(MyString &s1, MyString &s2);
};

MyString operator+(MyString &s1, MyString &s2) {
    MyString result;
    result.str = s1.str + s2.str;
    return result;
}*/

class MyString {
    private: 
    string s;

    public:
    MyString(string s=""){
        this->s = s;
    }

    void display(){
        cout<<s;
    }

    friend MyString operator+(MyString &s1, MyString &s2);
};

MyString operator+(MyString &s1, MyString &s2){
    MyString s3;
    s3.s = s1.s+s2.s;
    return s3.s;
}

int main()
{
    MyString s1("hello");
    MyString s2("world");

    MyString s3 = s1 + s2;
    
    s3.display();
    
}
