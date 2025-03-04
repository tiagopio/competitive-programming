#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<int>> graph;
vector<vector<bool>> used;

void dfs(int s, int p) {
  used[p][s] = true;
  for (auto u : graph[s]) {
    if (!used[p][u]) {
      dfs(u, p);
    }
  }
}

void solve() {
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);
  cin >> n;
  graph.resize(n + 1);
  used.resize(n + 1, vector<bool>(n + 1, false));
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) dfs(i, i);
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j <= n; j++) ok &= (used[j][i]);
    if (ok) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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
