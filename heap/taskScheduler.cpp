#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
int leastInterval(vector<char> &tasks, int n) {
  vector<int> freq(26, 0);

  for (char c : tasks)
    freq[c - 'A']++;

  priority_queue<int> pq;

  for (int f : freq)
    if (f)
      pq.push(f);

  int time = 0;
  while (!pq.empty()) {
    vector<int> temp;
    for (int i = 1; i <= n + 1; i++) {
      if (!pq.empty()) {
        int freq = pq.top();
        pq.pop();
        freq--;
        temp.push_back(freq);
      }
    }

    for (int &f : temp) {
      if(f>0)
      pq.push(f);
    }

    if (pq.empty())
      time += temp.size();
    else
      time += n + 1;
  }
  return time;
}
int leastInterval(vector<char> &tasks, int n) {
  vector<int> mpp(26, 0);
  for (char c : tasks) {
    mpp[c - 'A']++;
  }

  int maxFreq = *max_element(mpp.begin(), mpp.end());

  int maxCount = 0;
  for (int x : mpp) {
    if (x >= maxFreq)
      maxCount++;
  }

  return max((int)tasks.size(), ((maxFreq - 1) * (n + 1) + maxCount));
}
