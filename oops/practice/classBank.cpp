#include <iostream>
#include <string>
using namespace std;

// Class definition for BankAccount
class BankAccount {
private:
    string accountHolder; // Name of the account holder
    int accountNumber;    // Account number
    float balance;        // Account balance

public:
    // Function to accept input for account details
    void getInput() {
        cout << "Enter Account Holder's Name: ";
        cin.ignore(); // To handle newline character from previous input
        getline(cin, accountHolder);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Function to deposit money into the account
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to display account details
    void displayDetails() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Create an object of the BankAccount class
    BankAccount account;

    // Initialize the account
    account.getInput();

    // Perform deposit operation
    float depositAmount;
    cout << "\nEnter amount to deposit: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    // Perform withdrawal operation
    float withdrawAmount;
    cout << "\nEnter amount to withdraw: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    // Display final account details
    cout << "\nFinal Account Details:" << endl;
    account.displayDetails();

    return 0;
}