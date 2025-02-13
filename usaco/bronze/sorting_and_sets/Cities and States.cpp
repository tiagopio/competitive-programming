#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);

  int n;
  cin >> n;
  vector<pair<string, string>> a(n);
  for (int i = 0; i < n; i++) {
    string c, s;
    cin >> c >> s;
    c = c.substr(0, 2);
    a.emplace_back(c, s);
  }

  map<string, int> seen;
  int ans = 0;
  for (auto &[c, s] : a) {
    if (c != s) ans += seen[s + c];
    seen[c + s]++;
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
