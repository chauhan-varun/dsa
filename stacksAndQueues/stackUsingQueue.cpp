#include <bits/stdc++.h>
using namespace std;
class Stack {
  public:
  queue<int> q;

  void push(int x){
    // 1,2,3,4,5
    int s = q.size();
    q.push(x);
    for(int i = 0; i<s; i++){
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int top() {
    return q.front();
  }
};
