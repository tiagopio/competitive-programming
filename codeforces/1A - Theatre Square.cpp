// 233589943 	Nov/20/2023 12:48UTC-3 	tiagowhk 	A - Theatre Square 	GNU C++20 (64) 	Accepted 	858 ms 	0 KB
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve() {
  ll n, m, a, c1 = 0, c2 = 0;
	cin >> n >> m >> a;
			
	while (n > 0) {
		n -= a;
		c1++;
	}
	if (m != a) {
		while (m > 0) {
			m -= a;
			c2++;
		}
	} else {
		c2 = 1;
	}
	
	cout << c1 * c2 << endl;
	
	return 0;
}

int main() {
	solve();
	return 0;
}
