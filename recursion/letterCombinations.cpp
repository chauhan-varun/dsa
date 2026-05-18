#include <bits/stdc++.h>
using namespace std;
vector<string> letterCombinations(string digits) {
  if (digits.empty())
    return {};

  vector<string> res;
  vector<string> mpp = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};

  function<void(int, string)> backtrack = [&](int i, string s) {
    if (s.size() == digits.size()) {
      res.push_back(s);
      return;
    }

    for (char &c : mpp[digits[i] - '0']) {
      backtrack(i + 1, s + c);
    }
  };

  backtrack(0, "");

  return res;
}
