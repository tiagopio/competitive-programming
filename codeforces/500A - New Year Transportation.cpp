// 237804112	Dec/18/2023 13:13UTC-3	tiagowhk	500A - New Year Transportation	GNU C++20 (64)	Accepted	46 ms	1100 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, t, c, i;
  cin >> n >> t;
  t--;
  int pos[300000];
  int a = 1;

  for (int i = 0; i < n - 1; i++) {
    cin >> pos[i];
  }

  for (c = 0; c < n; ) {
    if (c == t) {
      cout << "YES\n";
      return;
    } else if (c > t) {
      cout << "NO\n";
      return;
    }
    i = pos[c] + c;
    if (i >= n) {
      cout << "NO\n";
      return;
    }
    c = i;
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
