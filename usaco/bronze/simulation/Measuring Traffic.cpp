#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);

  int n, a[100], b[100];
  string t[100];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i] >> a[i] >> b[i];

  int x = 0, y = 1e9;
  for (int i = n - 1; i >= 0; i--) {
    if (t[i] == "none") x = max(x, a[i]), y = min(y, b[i]);
    if (t[i] == "off") x += a[i], y += b[i];
    if (t[i] == "on") x -= b[i], y -= a[i], x = max(0LL, x);
  }
  cout << x << ' ' << y << '\n';

  x = 0, y = 1e9;
  for (int i = 0; i < n; i++) {
    if (t[i] == "none") x = max(x, a[i]), y = min(y, b[i]);
    if (t[i] == "on") x += a[i], y += b[i];
    if (t[i] == "off") x -= b[i], y -= a[i], x = max(0LL, x);
  }
  cout << x << ' ' << y  << '\n';
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