/*
  Task:	Trailing Zeros
  Sender:	tiagopio
  Submission time:	2024-03-05 17:34:12 +0200
  Language:	C++20
  Status:	READY
  Result:	ACCEPTED
*/

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef long double ld;
const int N = 2e5+10;
const int mod = 1e9+7;
const ll inf = 1e9+10;
 
void solve() {
  ll n;
  cin >> n;
 
  ll ans = 0;
  for (int i = 5; i <= n; i *= 5) {
    ans += n / i;
  }
  cout << ans << endl;
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
