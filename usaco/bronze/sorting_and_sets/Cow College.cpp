#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  int ans = 0, qtd = 0, mx = *max_element(a.begin(), a.end());
  for (int i = 1; i <= mx; i++) {
    int p = lower_bound(a.begin(), a.end(), i) - a.begin();
    int tmp = (n - p) * i;
    if (tmp > ans) {
      ans = tmp;
      qtd = i;
    }
  }
  cout << ans << ' ' << qtd << '\n';
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
