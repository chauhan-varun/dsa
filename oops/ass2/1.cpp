#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int rollNo;
    float marks;
};

int main()
{
    Student s1;
    ofstream fout("student.txt");
    if(fout.is_open()){
        s1.name = "varun";
        s1.rollNo = 276;
        s1.marks = 98;
        fout<<s1.name<<" "<<s1.rollNo<<" "<<s1.marks<<endl;
        fout.close();
    } else {
        cout<<"unable to open file for writing"<<endl;
        

    }

    ofstream appendFile("student.txt", ios::app);
    if(appendFile.is_open()){
        s1.name = "preety";
        s1.marks = 89;
        s1.rollNo = 199;
        appendFile<<s1.name<<" "<<s1.marks<<" "<<s1.rollNo<<endl;
        appendFile.close();
    } else {
        cout<<"unable to open file for appending"<<endl;
    }

    ifstream fin("student.txt");
    if(fin.is_open()){
        while(fin>>s1.name>>s1.marks>>s1.rollNo){
            cout<<"Name: "<<s1.name<<"\nMarks: "<<s1.marks<<"\nRoll No.: "<<s1.rollNo<<"\n"<<endl;
        }
        fin.close();
    } else {
        cout<<"unable to open file for reading";
    }

}