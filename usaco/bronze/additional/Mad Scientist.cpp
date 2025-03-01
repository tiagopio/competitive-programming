#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);

  int n; 
  string a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    if (a[i] == b[i]) continue;
    while(j < n and a[j] != b[j]) j++; 
    i = j - 1;
    ans++;
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
