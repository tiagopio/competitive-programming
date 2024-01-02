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

void solve() {
  int n, k, s = 0, tmp, num_tmp;
  map<int, int> m;
  cin >> n >> k;
  
  for (int i = 0; i < n; i++) {
    int e; cin >> e;
    m[e]++;
  }

  if (k == 0) {
    for (auto i : m) {
      if (i.first > 1) {
        cout << 1 << endl;
        return;
      } else {
        cout << -1 << endl;
        return;
      } 
    }
  }

  for (auto i : m) {
    if (s + i.second >= k) {
      tmp = i.second;
      num_tmp = i.first;
      break;
    }
    else s += i.second;
  }
  if (s + tmp > k) {
    cout << -1 << endl;
  } else {
    cout << num_tmp << endl;
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
