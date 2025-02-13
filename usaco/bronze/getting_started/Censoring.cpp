#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string a, b;
  cin >> a >> b;
  
  string ans;
  for (char c : a) {
    ans.push_back(c);
    if (ans.length() >= b.length() and ans.substr(ans.length() - b.length()) == b) {
      ans.resize(ans.length() - b.length());
    }
  }
  cout << ans << '\n';
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