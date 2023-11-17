// 233153701 	Nov/17/2023 12:42UTC-3 	tiagowhk 	C - Yarik and Array 	GNU C++17 	Accepted 	202 ms 	800 KB
#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ms = a[0];
  long long cs = a[0];

  for (int i = 1; i < n; i++) {
    if ((a[i] % 2 == 0 && a[i - 1] % 2 != 0) || (a[i] % 2 != 0 && a[i - 1] % 2 ==0)) {
      cs = max(cs + a[i], static_cast<long long>(a[i]));
    } else {
      cs = a[i];
    }
      ms = max(ms, cs);
  }

  cout << ms << endl;

  return 0;
}

int main()
{
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
