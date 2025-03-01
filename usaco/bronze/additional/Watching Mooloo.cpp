#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  int ans = k + 1, last = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] - last < k + 1) ans += (a[i] - last);
    else ans += k + 1;
    last = a[i];
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
