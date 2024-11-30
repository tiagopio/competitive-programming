#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int qtd = 0;
    for (int j = 0; j < n; j++) {
      if (i != j and a[j] >= a[i]) {
        if (abs(a[i] - a[j]) <= k) qtd++;
      }
    }
    ans = max(ans, qtd);
  }
  cout << ans + 1 << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
