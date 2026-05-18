#include <bits/stdc++.h>
#include <stack>
using namespace std;
class StockSpanner {
public:
  stack<pair<int, int>> st;
  int i;
  StockSpanner() {
    st = stack<pair<int, int>>();
    i = -1;
  }

  int next(int price) {
    i++;
    int ans = 0;
    while (!st.empty() && st.top().first < price)
      st.pop();

    ans = i - (st.empty() ? -1 : st.top().second);

    st.push({price, i});
    return ans;
  }
};
