#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("milkorder.in", "r", stdin);
  freopen("milkorder.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> q(n + 1, -1), order(m), pos(n + 1, -1);
  set<int> order_set;
  for (int i = 0; i < m; i++) cin >> order[i], order_set.insert(order[i]);
  for (int i = 0; i < k; i++) {
    int u, v; cin >> u >> v;
    q[v - 1] = u;
    pos[u] = v - 1;
  }

  for (int i = 0; i < n; i++) {
    if (q[i] == 1) {
      cout << i + 1 << '\n';
      return;
    }
    if (q[i] != -1) continue;
    q[i] = 1;

    int id = 0, start = 0;
    while(id < m) {
      if (pos[order[id]] != -1) {
        start = pos[order[id]];
        id++;
        continue;
      }
      if (order[id] == 1) {
        id++;
        continue;
      }
      for (int j = start; j < n; j++) {
        if (q[j] == -1) {
          q[j] = order[id];
          start = j;
          break;
        }
      }
      id++;
    }
    vector<int> tmp;
    for (int j = 0; j < n; j++) if (order_set.count(q[j])) tmp.push_back(q[j]);
    
    if (order == tmp) {
      cout << i + 1 << '\n';
      return;
    }

    for (int j = 0; j < n; j++) {
      if (q[j] != -1 and order_set.count(q[j]) and pos[q[j]] == -1) q[j] = -1;
    }
    q[i] = -1;
  }
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
