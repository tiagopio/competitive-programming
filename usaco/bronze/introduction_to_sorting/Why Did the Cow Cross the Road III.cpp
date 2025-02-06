#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);

  int n;
  cin >> n;
  
  vector<pair<int, int>> cows(n);
  for (int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
  sort(cows.begin(), cows.end());

  int ans = cows[0].first + cows[0].second;
  for (int i = 1; i < n; i++) {
    ans = max(ans, cows[i].first);
    ans += cows[i].second;
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
