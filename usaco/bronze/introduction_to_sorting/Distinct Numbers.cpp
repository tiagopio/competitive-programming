#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; 
  cin >> n;
  set<int> ans;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ans.insert(x);
  }
  cout << ans.size() << '\n';
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