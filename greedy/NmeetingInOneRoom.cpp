#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; }
int maxMeetings(vector<int> &start, vector<int> &end) {
  vector<pair<int, int>> meetings;
  for (int i = 0; i < start.size(); i++) {
    meetings.push_back({start[i], end[i]});
  }

  sort(meetings.begin(), meetings.end(), cmp);

  int cnt = 0, prev = -1;

  for (int i = 0; i < start.size(); i++) {
    if (prev <= meetings[i].first) {
      cnt++;
      prev = meetings[i].second;
    }
  }
  return cnt;
}
