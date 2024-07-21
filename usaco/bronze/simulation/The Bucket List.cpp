#include <bits/stdc++.h>
using namespace std;

const int MAX = int(1e3+1);

void solve() {
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> change(MAX);

  for (int i = 0; i < n; i++) {
    int s, t, b; cin >> s >> t >> b;
    change[s] += b, change[t] -= b;
  }

  int ans = 0, curr = 0;
  for (int i = 0; i < MAX; i++) {
    curr += change[i];
    ans = max(ans, curr);
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