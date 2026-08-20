#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<int, int> mpp;
  for (int i = 0; i < 5; i++) {
    int a;
    cin >> a;
    mpp[a]++;
  }

  bool fullHouse = (mpp.size() == 2 &&
                    (mpp.begin()->second == 2 || mpp.begin()->second == 3));

  cout << (fullHouse ? "Yes" : "No") << endl;
  return 0;
}
