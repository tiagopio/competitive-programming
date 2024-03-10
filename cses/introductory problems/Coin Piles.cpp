/*
  Task:	Coin Piles
  Sender:	tiagopio
  Submission time:	2024-03-10 19:39:00 +0200
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
const int N = 1e4+10;
const int mod = 1e9+7;
const ll inf = 1e9+10;
 
void solve() {
  ll a, b;
  cin >> a >> b;
  
  cout << ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a ? "YES\n" : "NO\n") << endl;
 
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
