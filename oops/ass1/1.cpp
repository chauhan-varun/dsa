/*
Write a C++ program with the help of a base class student having all details. Use
multiple and multilevel inheritance classes to show the result of the student.
*/

#include<iostream>
#include<string>
using namespace std;

class Student {
    protected:
    string name;
    int age;

    public:
    void setDetails(){
        cout<<"Enter your age: ";
        cin>>age;
        cout<<"Enter your name: ";
        cin.ignore();
        getline(cin, name);
    }

    void getDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }

};

class Test : public Student {
    protected:
    float english;
    float maths;

    public:
    void setMarks(){
        cout<<"Enter the English Marks: ";
        cin>>english;

        cout<<"Enter the Maths Marks: ";
        cin>>maths;
    }

    void getMarks(){
        cout<<"English Marks: "<<english<<endl;
        cout<<"Maths Marks: "<<maths<<endl;
    }
};

class Sports {
    protected: 
    int sportsMarks;

    public:
    void setSportMarks(){
        cout<<"Enter sports marks: ";
        cin>>sportsMarks;
    }
    void getSportMarks(){
        cout<<"sports marks: "<<sportsMarks<<endl;

    }
};

class Result : public Test, public Sports {
    private:
    int total;

    public:
    void calculate(){
        total = english + maths + sportsMarks;
    }

    void getResult(){
        getDetails();
        getMarks();
        getSportMarks();
        cout<<"Total Marks: "<<total<<endl;
    }
};

int main(){

    Result r;
    r.setDetails();
    r.setMarks();
    r.setSportMarks();
    r.calculate();
    r.getResult();
}