#include <bits/stdc++.h>
using namespace std;

void solve() {
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  
  int m, n, k;
  cin >> m >> n >> k;
  vector<string> grid(m);
  for (int i = 0; i < m; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      int times = k, pos = 0;
      while(pos < n) {
        times--;
        cout << grid[i][pos];
        if (times == 0) pos++, times = k;
      }
      cout << '\n';
    }
  }
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