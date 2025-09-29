#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    vector<vector<int>> canonical(n / 2);
    for (auto &x : canonical) x.resize(n / 2);
    int ans = 0;
    auto apply = [&](int x, int y, int scale) -> void {
        if (grid[x][y] == '.') return;
        x = min(x, n - 1 - x);
        y = min(y, n - y - 1);
        ans -= min(canonical[x][y], 4 - canonical[x][y]);
        canonical[x][y] += scale;
        ans += min(canonical[x][y], 4 - canonical[x][y]);
    };
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) apply(i, j, 1);
    cout << ans << '\n';
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        apply(x, y, -1);
        grid[x][y] = '#' + '.' - grid[x][y];
        apply(x, y, 1);
        cout << ans << '\n';
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