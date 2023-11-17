// 233109302 	Nov/17/2023 11:44UTC-3 	tiagowhk 	A - Game with Integers 	GNU C++17 	Accepted 	0 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  cin >> n;

  if (n % 3 == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;
  if (t < 1 || t > 100) return 0;

  while(t--) {
    solve();
  }
  return 0;
}
