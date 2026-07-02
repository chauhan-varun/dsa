#include <bits/stdc++.h>
#include <vector>
using namespace std;
static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
int eraseOverlapIntervals(vector<vector<int>> &intervals) {

  sort(intervals.begin(), intervals.end(), cmp);

  int nonOverlapping = 1, prev = intervals[0][1];
  for (auto it : intervals) {
    if (it[0] >= prev) {
      nonOverlapping++;
      prev = it[1];
    }
  }
  return intervals.size() - nonOverlapping;
}
