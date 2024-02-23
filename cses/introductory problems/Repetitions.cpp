/*
  Task:	Repetitions
  Sender:	tiagopio
  Submission time:	2024-02-23 15:19:46 +0200
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
  string s;
  cin >> s;
  
  int sum = 0, ans = -inf;
  char a = s[0];
  for (int i = 1; i < (int)s.length(); i++) {
    if (s[i] == a) {
       sum++;
       if (sum > ans) ans = sum;
    } else {
      sum = 0;
      a = s[i];
    }
  }
  if (ans == -inf) cout << 1 << endl;
  else cout << ans + 1 << endl;
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
