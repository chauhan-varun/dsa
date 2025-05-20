#include <iostream>
#include <string>
using namespace std;

// Define a structure to store student information
struct Student {
    string name;
    int rollNumber;
    float marks;
};

int main() {
    // Create a student structure variable
    Student student;

    // Input student information
    cout << "Enter student's name: ";
    getline(cin, student.name);
    cout << "Enter student's roll number: ";
    cin >> student.rollNumber;
    cout << "Enter student's marks: ";
    cin >> student.marks;

    // Display student information
    cout << "\nStudent Information:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Marks: " << student.marks << endl;

    return 0;
}