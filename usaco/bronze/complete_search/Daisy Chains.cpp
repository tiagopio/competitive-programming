#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) cin >> a[i];
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    double avg = 0;
    vector<double> avgs;
    for (int j = i; j < n; j++) {
      avg += a[j];
      avgs.push_back(avg / (double)(j - i + 1));
    }

    for (int id = 0; id < avgs.size(); id++) {
      for (int k = i; k <= i + id ; k++) {
        if (a[k] == avgs[id]) {ans++; break;}
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
  while (t--) {
    solve();
  }
  return 0;
}
