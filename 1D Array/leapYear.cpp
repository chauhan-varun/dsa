#include <iostream>
using namespace std;

int main() {
  
  int x;
  int y;
  cin >> y;
  if (y % 400) {
    cout << "its a leap year";
  } else if (y % 100) {
    cout << "its not a leap year";
  } else if (y % 4) {
    cout << "its a leap year";
  } else {
    cout << "its not a leap year";
  }
}
