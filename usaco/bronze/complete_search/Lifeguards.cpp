#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());

  int ans = -INF;
  for (int i = 0; i < n; i++) {
    auto p = a[i];
    a.erase(a.begin() + i);
    int tmp = 0;
    for (int k = 0; k < a.size(); k++) {
      int start = a[k].first;
      int end = a[k].second;
      int j = k;
      while(j + 1 < a.size() and a[j + 1].first <= end) j++, end = a[j].second;
      k = j;
      tmp += end - start;
    }
    ans = max(ans, tmp);
    a.insert(a.begin() + i, p);
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
