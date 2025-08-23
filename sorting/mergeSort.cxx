#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a.at(i) << " ";
  }
  cout << endl;
}
vector<int> merge(vector<int> &v1, vector<int> &v2) {
  int s1 = v1.size();
  int s2 = v2.size();
  vector<int> v(s1 + s2);
  int i = 0, j = 0, k = 0;
  while (i < s1 && j < s2) {
    if (v1[i] < v2[j]) {
      v[k] = v1[i];
      i++;
    } else {
      v[k] = v2[j];
      j++;
    }
    k++;
  }
  if (i == s1) {
    while (j < s2) {
      v[k] = v2[j];
      k++;
      j++;
    }
  }
  if (j == s2) {
    while (i < s1) {
      v[k] = v1[i];
      k++;
      i++;
    }
  }
  return v;
}
int main() {
  vector<int> v1;
  int a = 1;
  for (int i = 0; i < 4; i++) {
    v1.push_back(a);
    a += 2;
  }
  vector<int> v2;
  a = 2;
  for (int i = 0; i < 6; i++) {
    v2.push_back(a);
    a += 2;
  }

  display(v1);
  display(v2);
  vector<int> v = merge(v1, v2);
  display(v);
}