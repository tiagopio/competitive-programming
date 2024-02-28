/*
  Task:	Number Spiral
  Sender:	tiagopio
  Submission time:	2024-02-27 23:14:49 +0200
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
  ll y, x;
  cin >> y >> x;
 
  if (y == x) cout << y * x - (y - 1) << endl;
  else if (y > x) {
    ll e = max(y, x) * max(y, x) - ((max(y, x) - 1));
    if (y & 1) {
      cout << e - (max(y, x) - min(y, x)) << endl;
    } else {
      cout << e + (max(y, x) - min(y, x)) << endl;
    }
  } else {
    ll e = max(y, x) * max(y, x) - ((max(y, x) - 1));
    if (x & 1) {
      cout << e + (max(y, x) - min(y, x)) << endl;
    } else {
      cout << e - (max(y, x) - min(y, x)) << endl;
    }
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
