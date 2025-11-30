#include <bits/stdc++.h>
using namespace std;

int main() {
  int size, idx = 0, ele, i;
  cout << "Enter the size of Array";
  cin >> size;

  int arr[size];
  idx = size;

  cout << "enter the elements" << endl;
  for (int j = 0; j < size; j++) {
    cin >> arr[j];
  }

  while (true) {
    int choice;
    cout << "Enter the Choice: "; // append, insert, delete
    cin >> choice;

    switch (choice) {

    case 1:
      cout << "enter value to append" << endl;
      cin >> ele;
      arr[idx] = ele;
      idx++;
      break;

    case 2:
      cout << "enter value to append" << endl;
      cin >> ele;
      cout << "at index?" << endl;
      cin >> i;

      if (i >= 0 && i < size) {
        for (int j = idx; j > i; j--) {
          arr[j] = arr[j -1];
        }
        arr[i] = ele;
        idx++;
      } else {
        cout << "invalid Position" << endl;
      }
      break;
    case 3:
      cout << "enter the position to delete";
      cin >> i;
      if (i >= 0 && i <= idx) {
        for (int j = i; j < idx -1; j++) {
          arr[j] = arr[j + 1];
        }
        idx--;
      } else {

        cout << "invalid Position" << endl;
      }
      break;
    case 4:
      return 0;
    }
  }
  return 0;
}
