#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

ll minimumCostToConnectSticks(vector<int> &arr) {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int x : arr)
    pq.push(x);

  ll ans = 0;
  while (pq.size() > 1) {
    ll a = pq.top();
    pq.pop();

    ll b = pq.top();
    pq.pop();
    ll sum = a + b;
    ans += sum;
    pq.push(sum);
  }
  return ans;
}
int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
      cin >> x;
    ll ans = minimumCostToConnectSticks(arr);
    cout << ans << endl;
  }
}
