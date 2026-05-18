#include <bits/stdc++.h>
#include <functional>
using namespace std;
bool exist(vector<vector<char>> &board, string word) {

  int n = board.size(), m = board[0].size();
  function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
    if (k == word.size())
      return true;
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k])
      return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) ||
                  backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1));
    board[i][j] = temp;
    return found;
  };
  
  for(int i=0; i<n; i++){
      for(int j = 0; j<m; j++){
          if(backtrack(i, j, 0)) return true;
      }
  }
  return false;
}
