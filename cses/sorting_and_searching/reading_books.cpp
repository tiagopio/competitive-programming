#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int s = accumulate(a.begin(), a.end() - 1, 0ll);
    cout << ((a[n - 1] <= s) ? a[n - 1] + s : 2 * a[n - 1]) << '\n';
}
 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

/* Solution Notes {{{



}}} */