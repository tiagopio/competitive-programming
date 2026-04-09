#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> graph[110];
bool used[110];

int dfs(int s, int x) {
    if (s == x) return 1;
    used[s] = true;
    int q = 0;
    for (auto u : graph[s]) {
        if (!used[u]) {
            q += dfs(u, x);
        }
    }
    return q;
}

void solve() {
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
        memset(used, 0, sizeof(used));
        ok &= (dfs(0, i) >= 2);
    }
    cout << ((ok) ? "No\n" : "Yes\n");
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) graph[i].clear();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(cin >> n >> m and n + m) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{ 

    from 0 to all other vertices we need
    two diffrent ways to reach them

    Complexity: O(p * (p + e))

}}} */