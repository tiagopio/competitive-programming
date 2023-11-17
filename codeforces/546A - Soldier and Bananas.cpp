// 233228920 	Nov/17/2023 20:25UTC-3 	tiagowhk 	546A - Soldier and Bananas 	GNU C++20 (64) 	Accepted 	15 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
  int k, n, w, total = 0;
  cin >> k >> n >> w;
    
  for (int i = 1 ; i <= w; i++) {
    total += i * k;
  }
  if (total < n) cout << 0 << endl;
  else cout << total - n << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
