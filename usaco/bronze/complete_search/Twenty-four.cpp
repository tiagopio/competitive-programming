#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int OP(char c, int x, int y) {
  if (c == '+') return x + y;
  if (c == '-') return x - y;
  if (c == '*') return x * y;
  if (c == '/') if (y and x % y == 0) return x / y;
  return INF;
}

bool check(int num) {
  return num != INF;
}

void solve() {
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  
  sort(a.begin(), a.end());

  int ans = 0;
  do {
    string s = "+-/*";
    for (int i = 0; i < (int)s.length(); i++) {
      for (int j = 0; j < (int)s.length(); j++) {
        for (int k = 0; k < (int)s.length(); k++) {
          // (((A op B) OP C) OP D)
          int t1 = OP(s[i], a[0], a[1]);
          int t2 = OP(s[j], t1, a[2]);
          int t3 = OP(s[k], t2, a[3]);

          if (check(t3) and t3 <= 24) ans = max(ans, t3);

          // ((A OP B) OP (C OP D))
          t1 = OP(s[i], a[0], a[1]);
          t2 = OP(s[k], a[2], a[3]);
          t3 = OP(s[j], t1, t2);

          if (check(t3) and t3 <= 24) ans = max(ans, t3);
        }
      }
    }
  } while(next_permutation(a.begin(), a.end()));
  cout << min(ans, 24LL) << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
