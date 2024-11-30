#include <bits/stdc++.h>
using namespace std;

#define int long long

int grid[11][21];

void solve() {
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);  

  int k, n;
  cin >> k >> n;

  for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int rec[21] = {0};
    for (int j = 0; j < k; j++) {
      bool start = false;
      for (int k = 0; k < n; k++) {
        if (grid[j][k] == i) start = true;
        if (start) rec[grid[j][k]]++;
      }
    }
    for (int j = 1; j <= 20; j++) if (rec[j] == k and j != i) ans++;
  }
  cout << ans << '\n';
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
