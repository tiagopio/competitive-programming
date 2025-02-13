#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n;
  cin >> n;

  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  
  int ans = INF;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      int e1 = a[i], e2 = a[j];
      a.erase(a.begin() + j);
      a.erase(a.begin() + i);

      vector<int> tmp = a;
      sort(tmp.begin(), tmp.end());
      int sum = 0;
      for (int i = 0; i < tmp.size() - 1; i += 2) sum += tmp[i + 1] - tmp[i];
      ans = min(ans, sum);
      
      a.insert(a.begin() + i, e1);
      a.insert(a.begin() + j, e2); 
    }
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
