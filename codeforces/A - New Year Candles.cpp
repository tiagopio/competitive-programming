// 237555892	Dec/16/2023 20:04UTC-3	tiagowhk	A - New Year Candles	GNU C++20 (64)	Accepted	0 ms	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int a, b, d, m;
  cin >> a >> b;
  
  int h = a;
  
  while (a >= b) {
      d = a / b;
      h += d;
      m = a % b;
      a = d + m;
  }
  cout << h << endl;
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
