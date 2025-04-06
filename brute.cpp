#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif

#define int long long

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  cout << 100 << '\n';
  for (int i = 1; i <= 100; i++) {
    cout << rng() % 1000 << ' ';
  }
  cout << '\n';
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