#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, 1);
        a.emplace_back(r, -1);
    }
    int ans = 0;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += a[i].second;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
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

    Line sweep
    L = +1
    R = -1

}}} */