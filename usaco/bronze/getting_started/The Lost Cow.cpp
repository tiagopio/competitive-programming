#include <bits/stdc++.h>
using namespace std;

bool check(int y, int min, int max) {
  return y >= min && y <= max;
}

void solve() {
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  
  int x, y;
  cin >> x >> y;
  int mult = 1, ans = 0;

  while(1) {
    int pos = x + mult;
    ans += abs(x - pos);

    if (!check(y, min(x, pos), max(x,pos))) {
      ans += abs(x - pos);
      mult *= -2;
    } else {
      ans -= abs(y - pos);
      break;
    }
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