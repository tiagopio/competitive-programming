#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("cownomics");
    int n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    int ans = 0;
    for (int j = 0; j < m; j++) {
        set<char> s1, s2;
        for (int k = 0; k < n; k++) s1.insert(a[k][j]);
        for (int k = n; k < 2 * n; k++) s2.insert(a[k][j]);
        bool ok = true;
        for (auto c : s1) ok &= (s2.count(c) == 0);
        ans += ok;
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