/*
  Task:	Missing Number
  Sender:	tiagopio
  Submission time:	2024-02-23 15:03:50 +0200
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
  int n;
  cin >> n;
  int vec[n] = {0};
 
  for (int i = 0; i < n - 1; i++) {
    int e; cin >> e;
    vec[e - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (!vec[i]) {
      cout << i + 1 << endl;
      break;
    }
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
