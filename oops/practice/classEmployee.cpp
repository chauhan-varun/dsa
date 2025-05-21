#include <iostream>
#include <string>
using namespace std;

// Class definition for Employee
class Employee {
private:
    string empName;    // Employee's name
    int empID;         // Employee ID
    float basicSalary; // Basic salary of the employee

public:
    // Function to accept input for employee details
    void getInput() {
        cout << "Enter Employee Name: ";
        cin.ignore(); // To handle newline character from previous input
        getline(cin, empName);
        cout << "Enter Employee ID: ";
        cin >> empID;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    // Function to calculate the net salary
    float calculateSalary() {
        float HRA = 0.2 * basicSalary; // 20% of basic salary
        float DA = 0.5 * basicSalary;  // 50% of basic salary
        return basicSalary + HRA + DA; // Net salary formula
    }

    // Function to display employee details and net salary
    void displayDetails() {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Net Salary: " << calculateSalary() << endl;
    }
};

int main() {
    // Create an object of the Employee class
    Employee emp;

    // Call member functions to take input, compute salary, and display details
    emp.getInput();
    cout << "\nEmployee Details:" << endl;
    emp.displayDetails();

    return 0;
}