#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

typedef struct cow {
  int s, t, c;
} cow;

typedef struct airc {
  int a, b, p, mc;
} airc;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<cow> a(n);
  vector<airc> b(m);

  for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].t >> a[i].c;
  for (int i = 0; i < m; i++) cin >> b[i].a >> b[i].b >> b[i].p >> b[i].mc;

  vector<int> barn(101, 0);
  for (int i = 0; i < n; i++) for (int j = a[i].s; j <= a[i].t; j++) barn[j] += a[i].c;
  
  int ans = INF;
  for (int mask = 0; mask < (1 << m); mask++) {
    vector<int> tmp = barn;
    int cost = 0;
    for (int j = 0; j < m; j++) {
      if (mask & (1 << j)) {
        for (int k = b[j].a; k <= b[j].b; k++) tmp[k] -= b[j].p;
        cost += b[j].mc;
      }
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
      for (int j = a[i].s; j <= a[i].t; j++) mx = max(mx, tmp[j]);
    }
    if (mx <= 0) ans = min(ans, cost);
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
