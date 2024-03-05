/*
  Task:	Two Sets
  Sender:	tiagopio
  Submission time:	2024-03-05 15:03:38 +0200
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
  
  int sum = n * (n + 1) / 2;
  if (n == 1 ||sum % 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    if (n & 1) {
      cout << (n / 2) + 1 << endl;
      for (int i = (n / 4) + 1; i <= n - (n / 4) - 1; i++) {
        cout << i << " ";
      }
      cout << endl;
      cout << (n / 2) << endl;
      for (int i = 1; i <= n / 4; i++) {
        cout << i << " ";
      }
      for (int i = n - (n / 4); i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << n / 2 << endl;
      for (int i = 1; i <= n / 4; i++) {
        cout << i << " ";
      }    
      for (int i = n - (n / 4) + 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
      cout << n / 2 << endl;
      for (int i = (n / 4) + 1; i <= n - (n / 4); i++) {
        cout << i << " ";
      }
      cout << endl;
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
