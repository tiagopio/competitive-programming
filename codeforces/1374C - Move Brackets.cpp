// 238284717	Dec/21/2023 13:00UTC-3	tiagowhk	1374C - Move Brackets	GNU C++20 (64)	Accepted	15 ms	1200 KB
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 2e5+5;
const ll inf = 1e9;

void solve() {
  int n;
  string s, sub = "()";
  cin >> n >> s;  

  while (1) {
    int p = s.find(sub);
    if (p != string::npos) {
      s.erase(p, sub.length());
    } else break;
  }
  
  cout << s.length() / 2 << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
