#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
int dfs(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int &n,
        int &m, int i, int j1, int j2) {
  if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    return -1e8;
  if (i == n - 1)
    return j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int dj1 = -1; dj1 <= 1; dj1++) {
    for (int dj2 = -1; dj2 <= 1; dj2++) {
      int val = 0;
      if (j1 == j2)
        val = grid[i][j1];
      else
        val = grid[i][j1] + grid[i][j2];
      val += dfs(dp, grid, n, m, i + 1, j1 + dj1, j2 + dj2);
      maxi = max(maxi, val);
    }
  }
  return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
  vector<vector<int>> front(m, vector<int>(m, 0));
  vector<vector<int>> curr(m, vector<int>(m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int maxi = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
          for (int dj2 = -1; dj2 <= 1; dj2++) {
            int nextJ1 = j1 + dj1;
            int nextJ2 = j2 + dj2;

            if (nextJ1 >= 0 && nextJ1 < m && nextJ2 >= 0 && nextJ2 < m) {
              int val;
              if (j1 == j2)
                val = grid[i][j1];
              else
                val = grid[i][j1] + grid[i][j2];

              val += front[nextJ1][nextJ2];
              maxi = max(maxi, val);
            }
          }
        }
        curr[j1][j2] = maxi;
      }
    }
    front = curr;
  }
  return front[0][m - 1];
}
