#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

int n, x, y;
vector<vector<int>> graph;
vector<vector<int>> d;
vector<bool> used;

void bfs(int s, int mat) {
    used[s] = true;
    d[mat][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto u : graph[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[mat][u] = d[mat][v] + 1;
            }
        }
    }
}

void solve() {
    cin >> n >> x >> y;
    graph.resize(n + 1);
    d.resize(n + 1, vector<int>(n + 1, 0));
    used.resize(n + 1, false);
    graph[x].push_back(y);
    graph[y].push_back(x);
    for (int i = 1; i <= n - 1; i++) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        used.assign(n, false);
        bfs(i, i);
    }
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) ans[d[i][j]]++;
        }
    }
    for (int i = 1; i <= n - 1; i++) cout << ans[i] << '\n';
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
    
    Run V bfs
    
    O((V + 1)^2)

}}} */