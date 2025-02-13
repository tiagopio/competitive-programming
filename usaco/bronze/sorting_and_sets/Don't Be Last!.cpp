#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> mp;
  
  mp["Bessie"] = 0;
  mp["Elsie"] = 0;
  mp["Daisy"] = 0;
  mp["Gertie"] = 0;
  mp["Annabelle"] = 0;
  mp["Maggie"] = 0;
  mp["Henrietta"] = 0;

  for (int i = 0; i < n; i++) {
    string s;
    int v;
    cin >> s >> v;
    mp[s] += v;
  }

  map<int, vector<string>> ans;
  for (auto i : mp) ans[i.second].push_back(i.first);

  auto p = ans.begin();
  p++;
  if (ans.size() == 1 or p->second.size() > 1) cout << "Tie\n";
  else cout << p->second[0] << '\n';
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
