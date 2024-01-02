// 239836574	Dec/31/2023 20:03UTC-3	tiagowhk	977A - Wrong Subtraction	GNU C++20 (64)	Accepted	0 ms	0 KB
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
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    if (n % 10 == 0) {
      n /= 10;
    } else n--;
  }
  cout << n << endl;
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
