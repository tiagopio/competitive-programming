// 237553265	Dec/16/2023 18:49UTC-3	tiagowhk	579A - Raising Bacteria	GNU C++20 (64)	Accepted	0 ms	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, a = 0;
  cin >> n;
  while(n) {
    if (n & 1) a++;
    n >>= 1;
  }
  cout << a << endl;
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
