#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &arr) {
  int ten = 0, five = 0;

  for (int x : arr) {
    if (x == 5)
      five++;
    else if (x == 10) {
      ten++;
      if (five)
        five--;
      else
        return false;
    } else {
      if (ten && five) {
        ten--;
        five--;
      } else if (five >= 3)
        five -= 3;
      else return false;
    }
  }
  return true;
}
