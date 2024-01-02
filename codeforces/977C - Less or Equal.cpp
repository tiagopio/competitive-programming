// 239837243	Dec/31/2023 20:30UTC-3	tiagowhk	977C - Less or Equal	GNU C++20 (64)	Accepted	171 ms	9500 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

map<ll, int> used;
vector<ll> a, b;
int n;

void dfs(ll x) {
  b.pb(x);
  used[x] = 1;
  for (int i = 0; i < n; i++) {
    if (!used[a[i]]) {
      if (a[i] == x * 2 || (x % 3 == 0 && a[i] == x / 3)) {
        dfs(a[i]);
      }
    }
  }
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    used.clear();
    b.clear();
    dfs(a[i]);
    if (b.size() == n) {
      for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
      }
      cout << endl;
      return;
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
