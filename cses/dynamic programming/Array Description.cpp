#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
 
#define int long long
const int N = 1e5+10;
const int M = 1e2+10;
const int mod = 1e9+7;
 
int n, m, a[N], dp[N][M];
 
bool ok(int x, int m) {
  return x >= 1 and x <= m;
}
 
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    if (a[0] == i or a[0] == 0) dp[1][i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= m; k++) {
      if (a[i - 1] != 0 and a[i - 1] != k) {
        dp[i][k] = 0;
        continue;
      }
      for (int x = k - 1; x <= k + 1; x++) {
        if (!ok(x, m)) continue;
        dp[i][k] = (dp[i][k] + dp[i - 1][x]) % mod;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % mod;
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