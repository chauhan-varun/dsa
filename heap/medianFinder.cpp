#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
  priority_queue<int> pMax;
  priority_queue<int, vector<int>, greater<int>> pMin;
  MedianFinder() {}

  void addNum(int num) {
    pMax.push(num);
    
    pMin.push(pMax.top());
    pMax.pop();

    if(pMax.size()< pMin.size()){
      pMax.push(pMin.top());
      pMin.pop();
    }
  }

  double findMedian() {
    if (pMax.size() > pMin.size())
      return pMax.top();
    else
      return (pMax.top() + pMin.top()) / 2.0;
  }
};
