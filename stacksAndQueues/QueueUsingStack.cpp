#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
  stack<int> s;
  stack<int> temp;

  void push(int x) {
    while (!s.size()) {
      temp.push(s.top());
      s.pop();
    }
    
    s.push(x);
    
    while(!temp.empty()){
      s.push(temp.top());
      temp.pop();
    }
  }

  
  int front() {
    if(!s.empty()) return -1;
    return s.top();
  }

  void pop(){
    if(s.size() ==0) return;
    s.pop();
  }
};
