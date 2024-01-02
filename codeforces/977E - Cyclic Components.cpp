// 239998280	Jan/02/2024 11:00UTC-3	tiagowhk	977E - Cyclic Components	GNU C++20 (64)	Accepted	155 ms	23400 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

int n, m;
int deg[N];
bool used[N];
vector<int> cmp, g[N];
 
void dfs(int x) {
  used[x] = true;
  cmp.pb(x);
  for (auto i : g[x]) {
    if (!used[i]) {
      dfs(i);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
    ++deg[u];
    ++deg[v];
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (!used[i]) {
      cmp.clear();
      dfs(i);
      bool ok = true;
      for (auto v : cmp) ok &= deg[v] == 2;
      if (ok) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
