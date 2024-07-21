#include <bits/stdc++.h>
using namespace std;

void solve() {
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n;
  cin >> n;
  vector<bool> p(3, false);
  vector<tuple<int, int, int>> sg;
  
  for (int i = 0; i < n; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--, c--;
    sg.emplace_back(a, b, c);
  }

  int ans = 0;
  for (int i = 0; i < 3; i++) {
    p[i] = true;
    int count = 0;
    for (auto [a, b, c] : sg) {
      swap(p[a], p[b]);
      count += p[c];
    }
    ans = max(ans, count);
    p.assign(3, false);
  } 
  cout << ans << '\n';
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