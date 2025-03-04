#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxN = (int)1e5+10;

int n, deg[mxN];

void solve() {
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b; 
    cin >> a >>  b;
    deg[a]++, deg[b]++;
  }
  cout << (*max_element(deg, deg + n)) + 1 << '\n';
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
