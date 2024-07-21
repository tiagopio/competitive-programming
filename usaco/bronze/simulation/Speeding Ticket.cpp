#include <bits/stdc++.h>
using namespace std;

void solve() {
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> road(101), cow(101);

  int pos = 1;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    while(a--) road[pos] = b, pos++;
  }
  pos = 1;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    while(a--) cow[pos] = b, pos++;
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++) ans = max(ans, cow[i] - road[i]);
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