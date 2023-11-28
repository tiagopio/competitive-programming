// 234616504 	Nov/27/2023 13:37UTC-3 	tiagowhk 	A - Chat room 	GNU C++20 (64) 	Accepted 	30 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 5;
const ll inf = 1e9;

void solve() {
  string s, h = "hello";
  cin >> s;

  int c = 0, p = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == h[c]) {
      c++;
      p++;
    }
  }

  if (p == 5)  {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
