#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3010;

int n, m;
set<int> graph[N];
int used[N], rmvd[N];

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int s) {
    used[s] = true;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(1);
    bool ok = true;
    for (int i = 1; i <= n; i++) ok &= (used[i]);
    cout << ((ok) ? "YES\n" : "NO\n");
    int x;
    for (int i = 1; i < n; i++) {
        cin >> x;    
        rmvd[x] = true;
        graph[x].clear();
        for (int j = 1; j <= n; j++) if (graph[j].count(x)) graph[j].erase(x);
        for (int j = 1; j <= n; j++) used[j] = 0;
        for (int j = 1; j <= n; j++) {
            if (!rmvd[j] and !used[j]) {
                dfs(j);
                break;
            }
        }
        ok = true;
        for (int j = 1; j <= n; j++) if (!rmvd[j]) ok &= (used[j]);
        cout << ((ok) ? "YES\n" : "NO\n");
    }
    cin >> x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("closing");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{

    Since the limits are small we can just simulate the process

    O(n * (n + m))

}}} */