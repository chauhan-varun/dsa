#include <bits/stdc++.h>
using namespace std;

vector<string> addOperators(string num, int x) {
  vector<string> res;

  function<void(int, long long, long long, string)> dfs =
      [&](int i, long long curr, long long prev, string expr) {
        if (i == num.size()) {
          if (curr == x)
            res.push_back(expr);
          return;
        }

        for (int j = i; j < num.size(); j++) {
          if (j > i && num[i] == '0')
            break;

          string curr_num = num.substr(i, j - i + 1);
          long long n = stoll(curr_num);
          if (i == 0) {
            dfs(j + 1, n, n, curr_num);
          } else {
            dfs(j + 1, curr + n, n, expr + '+' + curr_num);
            dfs(j + 1, curr - n, -n, expr + '-' + curr_num);
            dfs(j + 1, curr - prev + (prev * n), prev * n,
                expr + '*' + curr_num);
          }
        }
      };

  dfs(0, 0, 0, "");
  return res;
}
