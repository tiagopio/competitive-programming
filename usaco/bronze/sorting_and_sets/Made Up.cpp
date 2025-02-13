#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = (int)2e5+10;

void solve() {
  int n;
  cin >> n;

  vector<int> reca(MAX, 0), rec(MAX, 0);
  map<int, vector<int>> ids;

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    reca[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ids[x].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    rec[x]++;
  }

  int ans = 0;
  for (auto i : ids) {
    if (reca[i.first]) {
      for (int j = 0; j < i.second.size(); j++) {
        ans += (rec[i.second[j]] * reca[i.first]);
      }
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
