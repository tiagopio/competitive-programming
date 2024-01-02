// 239836836	Dec/31/2023 20:15UTC-3	tiagowhk	977B - Two-gram	GNU C++20 (64)	Accepted	15 ms	0 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, max = INT_MIN, c;
  string s;
  char ans[2];
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    char d = s[i];
    char e = s[i + 1];
    c = 0;
    for (int j = 0; j < n; j++) {
      char u = s[j];
      char z = s[j + 1];
      if (d == u && e == z) c++;
      if (c > max) {
        max = c;
        ans[0] = d;
        ans[1] = e;
      }
    }
  }
  cout << ans[0] << ans[1] << endl;
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
