// 238316479	Dec/21/2023 20:02UTC-3	tiagowhk	476A - Dreamoon and Stairs	GNU C++20 (64)	Accepted	15 ms	1300 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n, m;
  cin >> n >> m;
  
  if (n < m) {
    cout << -1 << endl;
    return;
  }
  
  vector<int> qtd;
  int min;
  if (n % 2 == 0) {
    min = n / 2;
  } else {
    min = (n / 2) + 1;
  }
  
  qtd.pb(min);  
  
  for (int i = min; i < n; i++) {
    min += 1;
    qtd.pb(min);
  }
  
  int min_p = INT_MAX;
  for (int i = 0; i < qtd.size(); i++) {
    int nmin = qtd[i];
    if (nmin < min_p && nmin % m == 0) {
      min_p = nmin;
    }
  }
  
  cout << min_p << endl;
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
