#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif

#define int long long
const int N = 1e2+10;
const int M = 1e3+10;

int n, a[N], dp[N][N * M];
bool ok[N * M];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= N * M; j++) {
      if (dp[i][j]) {
        dp[i + 1][j] = 1;
        ok[j + a[i]] = 1;
        dp[i + 1][j + a[i]] = 1;
      }
    }
  }
  int ans = 0;
  for (int i= 1; i < N * M; i++) ans += ok[i];
  cout << ans << '\n';
  for (int i = 1; i < N * M; i++) {
    if (ok[i]) cout << i << ' ';
  }
  cout << '\n';
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