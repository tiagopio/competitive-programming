// 235442909 	Dec/02/2023 18:00UTC-3 	tiagowhk 	230A - Dragons 	GNU C++20 (64) 	Accepted 	62 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, s;
  cin >> s >> n;
  vector<pair<int, int>> dg;
    
  int x, y;
  while (n--) {
    cin >> x;
    cin >> y;
  
    dg.pb({x, y});

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first < b.first;
    };

    sort(dg.begin(), dg.end(), cmp);
  } 
  
  int p = 0;
  for (int i = 0; i < dg.size(); i++) {
      if (s > dg[i].first) {
      s += dg[i].second;
      p++;
    }
  }

  if (p == dg.size()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
} 
