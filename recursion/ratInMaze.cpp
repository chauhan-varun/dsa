#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
vector<string> ratInMaze(vector<vector<int>> &maze) {
  int n = maze.size() - 1, m = maze[0].size() - 1;

  vector<string> ans;
  function<void(int, int, string)> dfs = [&](int i, int j, string temp) {
    if (i < 0 || j < 0 || i > n || j > m || maze[i][j] == 0)
      return;

    maze[i][j] = 0;

    if (i == n && j == m) {
      ans.push_back(temp);
      maze[i][j] = 1;
      return;
    }
    dfs(i + 1, j, temp + "D");
    dfs(i, j - 1, temp + "L");
    dfs(i, j + 1, temp + "R");
    dfs(i - 1, j, temp + "U");
    maze[i][j] = 1;
  };
  dfs(0, 0, "");
  return ans;
}
