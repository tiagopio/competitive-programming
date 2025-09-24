#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("cowsignal");
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        string tmp;
        for (auto j : a[i]) {
            for (int l = 1; l <= k; l++) tmp.push_back(j);
        }
        for (int j = 1; j <= k; j++) cout << tmp << '\n';
    }
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