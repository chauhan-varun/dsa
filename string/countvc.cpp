#include <bits/stdc++.h>
using namespace std;
int main() {
  int vovals = 0, consonents = 0;
  string s = "hello world";
  for (int i = 0; i < s.size(); i++) {

    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      vovals++;
    } else {
      consonents++;
    }
  }

  cout<<"Vovals: "<< vovals<<endl;
  cout<<"Consonents: "<<consonents;
}
