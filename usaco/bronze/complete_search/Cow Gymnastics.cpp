#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("gymnastics");
    int k, n;
    cin >> k >> n;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            bool ok = true;   
            for (int i = 0; i < k; i++) {
                int idx, idy;
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == x) idx = j;
                    if (a[i][j] == y) idy = j;
                }
                ok &= (idx > idy);
            }
            ans += ok;
        }
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