#include <bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, char c, vector<vector<char>> &board) {
  for (int k = 0; k < 9; k++) {
    if (board[i][k] == c || board[k][j] == c ||
        board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
      return false;
  }
  return true;
}

void solveSudoku(vector<vector<char>> &board) {
    int n = board.size(), m = board[0].size();
    function<bool()> dfs = [&](){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='.'){
                    for(char c ='1'; c<='9'; c++){
                        if(isValid(i, j, c, board)){
                            board[i][j]= c;
                            if(dfs()) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    };
    dfs();
}
