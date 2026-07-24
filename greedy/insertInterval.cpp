#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> ans;
  int start = newInterval[0], end = newInterval[1], n = intervals.size(), i = 0;

  while (i < n && start > intervals[i][1])
    ans.push_back(intervals[i++]);

  while (i < n && intervals[i][0] <= end) {
    start = min(start, intervals[i][0]);
    end = max(end, intervals[i][1]);
    i++;
  }
    ans.push_back({start, end});
  while (i<n) {
    ans.push_back(intervals[i++]);
  }
  return ans;
}
