#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int MOD = 1e9+7;
 
int fexp(int x, int y, int m) {
	int r = 1;
	while(y) {
		if (y & 1) r = (r * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return r;
}
 
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << fexp(a, fexp(b, c, MOD - 1), MOD) << '\n';
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