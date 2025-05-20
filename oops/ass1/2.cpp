#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
    int s= 0;
    int e= str.length()-1;
    while(s<e){
        if(str[s]!=str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Convert to lowercase to make it case-insensitive
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}