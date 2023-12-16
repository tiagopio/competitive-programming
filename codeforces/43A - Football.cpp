// 237247857	Dec/14/2023 12:56UTC-3	tiagowhk	43A - Football	GNU C++20 (64)	Accepted	30 ms	0 KB
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
  
  map<string, int> m;
 	string s, ss = "0", sd;
 	int mx = INT_MIN, in;
 	while(n--) {
 		cin >> s;
 		if (m.find(s) == m.end()) {
 			m[s] = 1;
 			sd = s;
 		} else {
 			m[s]++;
 			in = mx; 			
 			mx = max(mx, m[s]);
 			if (mx != in) {
 				ss = s;
 			}
 		}
	}
	if (ss != "0") {
		cout << ss << '\n';
	} else {
		cout << sd << '\n';
	}
	
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
} 
