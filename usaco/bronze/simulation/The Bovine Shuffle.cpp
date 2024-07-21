#include <bits/stdc++.h>
using namespace std;

void solve() {
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);
  
  int n;
  cin >> n;
  vector<int> suffle(n);
  vector<pair<string, string>> cows(n);

  for (int i = 0; i < n; i++) cin >> suffle[i], suffle[i]--;
  for (int i = 0; i < n; i++) cin >> cows[i].first;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cows[j].second = cows[suffle[j]].first;
    }
    for (int j = 0; j < n; j++) {
      cows[j].first = cows[j].second;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << cows[i].second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}