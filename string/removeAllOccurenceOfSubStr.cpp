#include <bits/stdc++.h>
#include <string>
using namespace std;
string remove(string s, string p){
  while(s.find(p)!=string::npos){
    s.erase(s.find(p), p.size());
  }
  return s;
}
