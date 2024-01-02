// 240026222	Jan/02/2024 14:43UTC-3	tiagowhk	977F - Consecutive Subsequence	GNU C++20 (64)	Accepted	234 ms	19700 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, a[N];
  vector<int> ans;
  map<int, int> dp;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = 0, mx_num = 0;
  for (int i = 0; i < n; i++) {
    dp[a[i]] = dp[a[i] - 1] + 1;
    if (dp[a[i]] > mx) {
      mx = dp[a[i]];
      mx_num = a[i];
    }
  }
  cout << mx << '\n';
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == mx_num) {
      ans.pb(i);
      --mx_num;
    }
  }
  reverse(all(ans));
  for (int x : ans) cout << x + 1 << " ";
  cout << endl;
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
