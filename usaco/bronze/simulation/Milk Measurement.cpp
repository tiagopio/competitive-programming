#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int n;

void solve() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  
  cin >> n;
  vector<pair<int, pair<string, int>>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second.first >> a[i].second.second;
  sort(a.begin(), a.end());

  map<string, int> mp;
  int ans = 0;
  vector<string> display = {""};
  mp["Bessie"] = 7;
  mp["Elsie"] = 7;
  mp["Mildred"] = 7;

  for (auto [u, v] : a) {
    mp[v.first] += v.second;
    int mx = -INF;
    for (auto i : mp) mx = max(mx, i.second);
    vector<string> tmp;
    for (auto i : mp) if (i.second == mx) tmp.push_back(i.first);
    sort(display.begin(), display.end());
    sort(tmp.begin(), tmp.end());
    if (tmp != display) ans++;
    display = tmp;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}