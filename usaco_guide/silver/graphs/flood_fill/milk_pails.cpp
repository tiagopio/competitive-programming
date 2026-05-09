#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 101;

int x, y, k, m;
int d[MAX][MAX];

void solve() {
    cin >> x >> y >> k >> m;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    d[0][0] = 0;
    int ans = m;
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        int i = v.first;
        int j = v.second;
        ans = min(ans, abs(m - (i + j)));
        if (d[i][j] == k) continue;
        vector<pair<int, int>> n = {
            {x, j},
            {i, y},
            {0, j},
            {i, 0},
            {max(0ll, i - (y - j)), min(y, j + i)},
            {min(x, i + j), max(0ll, j - (x - i))}
        };
        for (auto u : n) {
            if (d[u.first][u.second] == -1) {
                d[u.first][u.second] = d[i][j] + 1;
                q.push(u);
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("pails");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}