#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int n;
  string s;
  cin >> n >> s;

  map<string, int> mp;
  for (int i = 0; i < n; i++) for (int j = i + 1; j <= n; j++) mp[s.substr(i, j - i)]++;
  
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (auto j : mp) if (j.first.length() == i) ok &= (j.second == 1);
    if (ok) {
      cout << i << '\n';
      return;
    }
  }

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