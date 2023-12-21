// 238316166	Dec/21/2023 19:49UTC-3	tiagowhk	742A - Arpa’s hard exam and Mehrdad’s naive cheat	GNU C++20 (64)	Accepted	15 ms	1300 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1 << endl;
    return;
  }
  int l[4] = {6, 8, 4, 2};
  
  cout << l[n % 4] << endl;
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
