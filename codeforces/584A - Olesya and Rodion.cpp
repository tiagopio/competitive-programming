// 238184334	Dec/20/2023 15:29UTC-3	tiagowhk	584A - Olesya and Rodion	GNU C++20 (64)	Accepted	15 ms	1200 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, t;
  cin >> n >> t;
  
  if (n == 1 && t == 10) {
    cout << -1 << endl;
    return;
  }
  
  if (t == 10) {
    for (int i = 0; i < n - 1; i++) {
      cout << 1;
    }
    cout << 0;
  }
  else {
    for (int i = 0; i < n; i++) {
      cout << t;
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
