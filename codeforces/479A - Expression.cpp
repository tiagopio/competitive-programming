// 234757864 	Nov/28/2023 10:16UTC-3 	tiagowhk 	479A - Expression 	GNU C++20 (64) 	Accepted 	15 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> results;

  for (int i = 0; i < 4; i++) {
    results.pb(a + b * c);
    results.pb(a * ( b + c));
    results.pb(a * b * c);
    results.pb((a + b) * c);
    results.pb(a + b + c);
  }
  
  cout << *max_element(results.begin(), results.end()) << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
} 
