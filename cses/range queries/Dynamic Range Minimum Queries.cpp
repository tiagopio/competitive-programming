#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int MAX = (int)2e5+10;
const int INF = 0x3f3f3f3f3f3f3f3f;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
 
// segtree
// merge, build, query, update
 
int n, q;
vector<int> a(MAX), segtree(4 * MAX);
 
int merge(int x, int y) {
  return min(x, y);
}
 
int build(int p, int l, int r) {
  if (l == r) return segtree[p] = a[l];
  int m = (l + r) / 2;
  return segtree[p] = merge(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}
 
int query(int a, int b, int p, int l, int r) {
  if (b < l or r < a) return INF;
  if (a <= l and r <= b) return segtree[p];
  int m = (l + r) / 2;
  return merge(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}
 
int update(int i, int x, int p, int l, int r) {
  if (i < l or r < i) return segtree[p];
  if (l == r) return segtree[p] = x;
  int m = (l + r) / 2;
  return segtree[p] = merge(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}
 
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  build(1, 0, n - 1);
 
  while(q--) {
    int op; cin >> op;
    op--;
    if (!op) {
      int k, u; cin >> k >> u;
      k--;
      update(k, u, 1, 0, n - 1);
    } else {
      int l, r; cin >> l >> r;
      l--, r--;
      cout << query(l, r, 1, 0, n - 1) << '\n';
    }
  }
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}