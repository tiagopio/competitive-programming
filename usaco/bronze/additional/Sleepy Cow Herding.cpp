#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  vector<int> a(3);
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a.begin(), a.end());

  if (a[0] == a[2] - 2) cout << 0 << '\n';
  else if ((a[1] == a[2] - 2) or (a[0] == a[1] - 2)) cout << 1 << '\n';
  else cout << 2 << '\n';
  cout << max(a[2] - a[1], a[1] - a[0]) - 1 << '\n';
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
