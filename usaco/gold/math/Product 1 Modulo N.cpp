#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxN = 1e5+10;

void solve() {
  int n;
  cin >> n;
  vector<bool> ok(mxN, false);
  int prod = 1;
  for (int i = 1; i < n; i++) {
    if (__gcd(n, i) == 1) {
      ok[i] = true;
      prod = (prod * i) % n;
    }
  }
  if (prod != 1) ok[prod] = false;
  cout << count(ok.begin() + 1, ok.end(), true) << '\n';
  for (int i = 1; i < n; i++) {
    if (ok[i]) cout << i << ' ';
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
