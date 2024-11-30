#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;
  int ans = -INF;
  for (int i = 0; i <= m / x; i++) {
    for (int j = 0; j <= m / y; j++) {
      int qtd = i * x + j * y;
      if (qtd <= m) ans = max(ans, qtd);
    } 
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
