#include <iostream>
using namespace std;
int main() {
  int x = 6;
  int count = 0;
  int a[] = {1, 3, 2, 7, 5, 9, 4, 3};
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      for (int k = j + 1; k < 8; k++) {
        if ((a[i] + a[j] + a[k]) == x)
          count++;
      }
    }
  }
  cout << count;
}
