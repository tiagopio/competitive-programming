#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x & 1) odd++;
    else even++;
  }

  int ans = 0;
  bool is_even = true;
  while(even + odd) {
    if (is_even) {
      if (even > 0) even--, ans++;
      else {
        if (odd >= 2) odd -= 2, ans++;
        else if (odd == 1) {
          ans--;
          break;
        } else break;
      }
    } else {
      if (odd > 0) odd--, ans++;
      else break;
    }
    is_even = !is_even;
  }
  cout << ans << '\n';
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
