#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void debug(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  cout << "(" << a.first << ", " << a.second << ")\n";
  cout << "(" << b.first << ", " << b.second << ")\n";
  cout << "(" << c.first << ", " << c.second << ")\n";
  cout << "\n\n";
}

void solve() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  
  int ans = -INF;
  for (int i = 0; i < n; i++) {
    auto point = a[i];
    for (int j = 0; j < n; j++) {
      if (i != j and point.second == a[j].second) {
        for (int k = 0; k < n; k++) {
          if (k != i and k != j and point.first == a[k].first) {
            // debug(point, a[j], a[k]);
            ans = max(ans, abs(point.first - a[j].first) * abs(point.second - a[k].second));
          }
        }
      }
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
