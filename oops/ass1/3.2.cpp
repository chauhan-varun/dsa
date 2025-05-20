#include <iostream>
#include <vector>

using namespace std;

void decimalToBinary(int decimal) {
    vector<int> binary;
    while(decimal>0){
        binary.push_back(decimal%2);
        decimal /= 2;
    }

    for(int i = binary.size()-1; i>=0; i--){
        cout<<binary[i];
    }
    cout<<endl;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0) {
        cout << "Binary representation: 0" << endl;
    } else {
        decimalToBinary(decimal);
    }

    return 0;
}