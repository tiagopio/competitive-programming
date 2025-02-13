#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAX = (int)2e5+10;
 
vector<pair<int, int>> a;
 
void solve() {
  int n, x; 
  cin >> n >> x;
 
  a.resize(n);
 
  for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
 
  sort(a.begin(), a.end());
 
  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1;
    while(l <= r) {
      int m = (l + r) / 2;
 
      if (a[m].first + a[i].first == x && a[m].second != a[i].second) {
        cout << a[i].second + 1 << ' ' << a[m].second + 1 << '\n';
        return;
      } else if (a[m].first + a[i].first  < x) l = m + 1;
      else r = m - 1;
    }
  }
  cout << "IMPOSSIBLE\n";
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