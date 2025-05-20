#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll_no;

public:
    // Constructor
    Student(string n, int r) : name(n), roll_no(r) {
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }

    // Method to display student information
    void display() const {
        cout << "Name: " << name << ", Roll Number: " << roll_no << endl;
    }
};

int main() {
    // Dynamically allocate memory for a Student object
    Student* student = new Student("Alice", 101);

    // Access the object's method
    student->display();

    // Deallocate memory
    delete student;

    return 0;
}