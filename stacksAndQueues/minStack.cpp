#include <bits/stdc++.h>
#include <climits>
#include <stack>
using namespace std;

class Stack {
  stack<pair<int, int>> s;

  public:
  void push(int x) {

    int min;
    if (s.empty()) {
      min = x;
    } else {
      min = std::min(s.top().second, x);
    }
    s.push({x, min});
  }
};

class Stacck {
  stack<int> st;
  long long min = LONG_LONG_MAX;

public:
  void push(int x) {
    if (st.empty()) {
      min = x;
      st.push(x);
    } else {
      if (x < min) {
        st.push(2 * x * 1LL - min);
        min = x;
      } else
        st.push(x);
    }
  }

  void pop() {
    if (st.empty())
      return;

    long long x = st.top();
    st.pop();
    if (x < min)
      min = 2 * min - x;
  }

  int top() {
    if (st.empty())
      return -1;
    long long x = st.top();
    if (x < min)
      return 2 * min - x;
    else
      return x;
  }

  int getMin() { return min; }
};

int main() {}
