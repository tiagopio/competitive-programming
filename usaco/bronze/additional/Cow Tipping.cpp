#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (grid[i][j] == '1') {
        ans++;
        for (int k = 0; k <= i; k++) {
          for (int l = 0; l <= j; l++) {
            if (grid[k][l] == '0') grid[k][l] = '1';
            else grid[k][l] = '0';
          }
        }
      }
    }
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
