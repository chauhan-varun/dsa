#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k) {
  int i = 0, sum = 0, lsum = 0, rsum = 0, n = cardPoints.size(), j = n - 1;

  while (i < k) {
    lsum += cardPoints[i++];
  }
  sum = max(sum, lsum);

  while (j < n - k) {
    lsum -= cardPoints[i--];
    rsum += cardPoints[j--];
    sum = max(sum, lsum + rsum);
  }
  return sum;
}
