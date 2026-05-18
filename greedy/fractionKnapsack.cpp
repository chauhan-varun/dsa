#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Item {
  int val, wt;
};
class Solution {
public:
  static bool cmp(Item a, Item b) {
    return ((double)a.val / a.wt > (double)b.val / b.wt);
  }
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
    int n = val.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
      items[i] = {val[i], wt[i]};
    }

    sort(items.begin(), items.end(), cmp);

    double total = 0.0;

    for (Item &it : items) {
      if (it.wt <= capacity) {
        capacity -= it.wt;
        total += it.val;
      } else {
        total += (((double)it.val / it.wt) * capacity);
        break;
      }
    }
    return total;
  }
};
