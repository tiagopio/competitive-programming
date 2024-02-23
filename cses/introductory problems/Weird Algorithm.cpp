/*
 Task:	Weird Algorithm
 Sender:	tiagopio
 Submission time:	2024-02-23 14:15:18 +0200
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
 
  cout << n << " ";
  while (n != 1) {
    if (n & 1) n = (n * 3) + 1;
    else n /= 2;
    cout << n << " ";
  }
  cout << "\n";
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
