#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)1e3+10;

int a[MAX];

void solve() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1, sum = 0;
    
    while(r > i) {
      sum += (r - i) * a[r], r--;
    }

    while(l < i){
      sum += ((n - (i - l)) * a[l]), l++;
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
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