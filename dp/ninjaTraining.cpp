#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &points, vector<vector<int>> &dp, int day,
        int lastActivity) {
  if (day == 0) {
    int maxi = INT_MIN;
    for (int activity = 0; activity < 3; activity++) {
      if (activity != lastActivity)
        maxi = max(maxi, points[day][activity]);
    }
    return maxi;
  }

  if (dp[day][lastActivity] != -1)
    return dp[day][lastActivity];

  int maxi = INT_MIN;
  for (int activity = 0; activity < 3; activity++) {
    if (activity != lastActivity)
      maxi =
          max(maxi, points[day][activity] + dfs(points, dp, day - 1, activity));
  }
  return dp[day][lastActivity] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<int> dp(4, 0);
  dp[0] = max(points[0][1], points[0][2]);
  dp[1] = max(points[0][0], points[0][2]);
  dp[2] = max(points[0][0], points[0][1]);
  dp[3] = max({points[0][1], points[0][0], points[0][2]});

  for (int day = 1; day < n; day++) {
    vector<int> temp(4, 0);

    for (int lastActivity = 0; lastActivity < 4; lastActivity++) {
      for (int activity = 0; activity < 3; activity++) {
        if (lastActivity != activity)
          temp[lastActivity] =
              max(temp[lastActivity],
                  points[day][activity] + dp[activity]);
      }
    }
    dp = temp;
  }
  return dp[3];
}
