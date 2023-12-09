// 236514294 	Dec/09/2023 11:34UTC-3 	tiagowhk 	B - Xenia and Ringroad 	GNU C++20 (64) 	Accepted 	62 ms 	800 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> ts(m);
  
  for (int i = 0; i < m; i++) {
    cin >> ts[i];
  }

  ll s = 0, a = 1, i = 0, p = 0;
  
  while (s != m) {
    if (a < ts[i]) {
      p += (ts[i] - a);
      a = ts[i];
    }

    if (a == ts[i]) {
      s++;
      i++;
      if (i == m) break;
    }
    
    if (a > ts[i]) {
      p += (n - a + 1);
      a = 1;
    }
  }

  cout << p << endl;

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
