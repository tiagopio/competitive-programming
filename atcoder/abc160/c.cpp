#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) a[i + m] = a[i] + n;
    int ans = INF;
    for (int i = 0; i < m; i++) ans = min(ans, a[i + m - 1] - a[i]);
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