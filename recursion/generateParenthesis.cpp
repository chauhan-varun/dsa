#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string curr = "";
    function<void(int, int)> generate = [&](int open, int close) {
      if (open == n && close == n) {
        res.push_back(curr);
        return;
      }

      if (open < n) {
        curr.push_back('(');
        generate(open + 1, close);
        curr.pop_back();
      }
      if (close < open) {
        curr.push_back(')');
        generate(open, close + 1);
        curr.pop_back();
      }
    };
    generate(0, 0);
    return res;
  }
};
