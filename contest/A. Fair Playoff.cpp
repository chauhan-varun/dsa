
#include <bits/stdc++.h>
using namespace std;

// ── Type aliases ──────────────────────────────────────────────
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// ── Macros ────────────────────────────────────────────────────
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define F first
#define S second
#define yes cout << "YES\n"
#define no cout << "NO\n"

// ── Debug (invisible on judge) ────────────────────────────────
#ifdef LOCAL
#define dbg(x) cerr << "[" << #x << "] = " << (x) << "\n"
#define dbg2(x, y)                                                             \
  cerr << "[" << #x << "]=" << (x) << "  [" << #y << "]=" << (y) << "\n"
#else
#define dbg(x)
#define dbg2(x, y)
#endif

// ── Setup ─────────────────────────────────────────────────────
void setup() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  ifstream fin("input.txt");
  cerr << "===== INPUT =====\n" << fin.rdbuf() << "=================\n\n";
  cerr << "===== OUTPUT ====\n";
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

// ── Solution ──────────────────────────────────────────────────
void solve() {
  int arr[4] = {};
  for (int i = 0; i < 4; i++) {
    cin >> arr[i];
  }
  int maxi = max(arr[0], arr[1]);
  int maxi2 = max(arr[2], arr[3]);
  if ((maxi < arr[2] && maxi < arr[3]) || maxi2 < arr[0] && maxi2 < arr[1]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

// ── Main ──────────────────────────────────────────────────────
int32_t main() {
  setup();

  int t;
  cin >> t;
  while (t--)
    solve();

#ifdef LOCAL
  cerr << "=================\n";
#endif
  return 0;
}
