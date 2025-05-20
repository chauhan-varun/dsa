#include <iostream>
#include <string>
using namespace std;

// Define a class to store student information
class Student {
private:
    string name;
    int roll_no;
    float marks;
    string mob_no;
    string email;

public:
    // Method to input student information
    void inputStudentInfo() {
        cout << "Enter student's name: ";
        getline(cin, name);
        cout << "Enter student's roll number: ";
        cin >> roll_no;
        cout << "Enter student's marks: ";
        cin >> marks;
        cin.ignore(); // To clear the input buffer
        cout << "Enter student's mobile number: ";
        getline(cin, mob_no);
        cout << "Enter student's email: ";
        getline(cin, email);
    }

    // Method to display student information
    void displayStudentInfo() const {
        cout << "\nStudent Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Marks: " << marks << endl;
        cout << "Mobile Number: " << mob_no << endl;
        cout << "Email: " << email << endl;
    }
};

int main() {
    // Create an object of the Student class
    Student student;

    // Input and display student information
    student.inputStudentInfo();
    student.displayStudentInfo();

    return 0;
}