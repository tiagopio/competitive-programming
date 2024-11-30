#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = (int)2e2+10;

char grid[MAX][MAX];

void solve() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
 
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < 2 * n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int rec1[26] = {0}, rec2[26] = {0};
    for (int j = 0; j < n; j++) rec1[grid[j][i] - 'A']++;
    for (int j = n; j < 2 * n; j++) rec2[grid[j][i] - 'A']++;

    bool ok = true;
    for (int i = 0; i < 26; i++) if (rec1[i] and rec2[i]) ok = false;
    ans += ok;
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
