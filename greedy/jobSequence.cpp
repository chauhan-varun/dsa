#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;
static bool cmp(pair<int, int> j1, pair<int, int> j2) {
  return (j1.second > j2.second);
}
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
  int n = deadline.size();
  vector<pair<int, int>> jobs;

  for (int i = 0; i < deadline.size(); i++) {
    jobs.push_back({deadline[i], profit[i]});
  }

  sort(jobs.begin(), jobs.end(), cmp);

  int maxDeadline = *max_element(deadline.begin(), deadline.end());
  vector<int> slot(maxDeadline + 1, -1);

  int job = 0, prof = 0;
  for (int i = 0; i < n; i++) {
    for(int j = jobs[i].first; j>0; j--){
      if(slot[j]==-1){
        job++;
        slot[i] = jobs[i].first;
        prof+= jobs[i].second;
      }
    }
  }
  return {job, prof};
}
