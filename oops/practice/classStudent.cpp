#include <iostream>
#include <string>
using namespace std;

// Class definition for Student
class Student {
private:
    string name;       // Student name
    int rollNumber;    // Roll number
    float marks[3];    // Marks of three subjects

public:
    // Function to take input for student details
    void inputDetails() {
        cout << "Enter Student Name: ";
        cin.ignore(); // To handle newline character from previous input
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Marks of Three Subjects: ";
        for (int i = 0; i < 3; ++i) {
            cin >> marks[i];
        }
    }

    // Function to calculate the total marks
    float calculateTotal() {
        float total = 0;
        for (int i = 0; i < 3; ++i) {
            total += marks[i];
        }
        return total;
    }

    // Function to display student details
    void displayDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Total Marks: " << calculateTotal() << endl;
    }
};

int main() {
    // Create 3 objects of the Student class
    Student student1, student2, student3;

    // Input details for each student
    cout << "Enter details for Student 1:" << endl;
    student1.inputDetails();

    cout << "Enter details for Student 2:" << endl;
    student2.inputDetails();

    cout << "Enter details for Student 3:" << endl;
    student3.inputDetails();

    // Display details for each student
    cout << "\nDetails of Student 1:" << endl;
    student1.displayDetails();

    cout << "\nDetails of Student 2:" << endl;
    student2.displayDetails();

    cout << "\nDetails of Student 3:" << endl;
    student3.displayDetails();

    return 0;
}