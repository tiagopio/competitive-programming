#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int n; 
int grid[5000][5000];

void solve() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  cin >> n;
  int ans = INF;
  int x = 2499, y = 2499;
  int acc = 0;
  for (int i = 0; i < n; i++) {
    char c; int n;
    cin >> c >> n;
    if (c == 'N') {
      while(n) {
        if (grid[x - 1][y]) {
          ans = min(ans, abs(grid[x - 1][y] - (acc + 1)));
        }
        x--;
        grid[x][y] = ++acc;
        n--;
      }
    } else if (c == 'S') {
      while(n) {
        if (grid[x + 1][y]) {
          ans = min(ans, abs(grid[x + 1][y] - (acc + 1)));
        }
        x++;
        grid[x][y] = ++acc;
        n--;
      }
    } else if (c == 'W') {
      while(n) {
        if (grid[x][y - 1]) {
          ans = min(ans, abs(grid[x][y - 1] - (acc + 1)));
        }
        y--;
        grid[x][y] = ++acc;
        n--;
      }
    } else {
      while(n) {
        if (grid[x][y + 1]) {
          ans = min(ans, abs(grid[x][y + 1] - (acc + 1)));
        }
        y++;
        grid[x][y] = ++acc;
        n--;
      }
    }
  }
  cout << ((ans == INF) ? -1 : ans) << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}