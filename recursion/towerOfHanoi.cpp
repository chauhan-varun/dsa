
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
  if (n == 0)
    return; // base case

  // Step 1: Move n-1 disks from source to helper
  towerOfHanoi(n - 1, source, destination, helper);

  // Step 2: Move the nth disk from source to destination
  cout << "Move disk " << n << " from " << source << " → " << destination
       << endl;

  // Step 3: Move n-1 disks from helper to destination
  towerOfHanoi(n - 1, helper, source, destination);
}

void toh(int n, char s, char h, char d) {
  if (n==0) return;
  toh(n-1, s, d,h);
  cout<<s<<"->"<<d<<endl;
  toh(n-1, h, s, d);
}

int main() {
  int n = 3; // number of disks
  towerOfHanoi(n, 'A', 'B', 'C');
  return 0;
}
