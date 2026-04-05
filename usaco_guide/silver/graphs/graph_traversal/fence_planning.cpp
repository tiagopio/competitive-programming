#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+10;

int n, m, l, r, u, d;
bool used[N];
vector<int> graph[N];
pair<int, int> cord[N];

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int s) {
    used[s] = true;
    l = min(l, cord[s].first);
    r = max(r, cord[s].first);
    u = max(u, cord[s].second);
    d = min(d, cord[s].second);
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cord[i].first >> cord[i].second;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            l = INF;
            r = -INF;
            u = -INF;
            d = INF;
            dfs(i);
            ans = min(ans, 2 * (r - l) + 2 * (u - d));
        } 
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("fenceplan");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{

    Let C be a connect component. The minimum rectangle perimeter
    is given by 2 * (max(Cx) - min(Cx)) + 2 * (max(Cy) - min(Cy))

    where max/min(Ci) | i in {x, y} returns the maximum x cordinate and 
    the minimum cordinate

    Complixty: O(n + m)

}}} */