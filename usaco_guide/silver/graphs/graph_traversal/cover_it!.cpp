#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> used;
vector<int> color;
vector<pair<int, int>> edges;
vector<vector<int>> graph;

void dfs(int s) {
    used[s] = true;
    for (auto u : graph[s]) {
        if (!used[u]) {
            edges.emplace_back(s, u);
            dfs(u);
        }
    }
}

void coloring(int s, int c) {
    used[s] = true;
    color[s] = c;
    for (auto u : graph[s]) {
        if (!used[u]) {
            coloring(u, c ^ 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    used.resize(n + 1, false);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        used[i] = false;
    }
    for (auto [u, v] : edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    color.resize(n + 1, -1);
    coloring(1, 0);
    int red = 0, blue = 0;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) red++;
        else blue++;
    }
    if (red <= n / 2) {
        cout << red << '\n';
        for (int i = 1; i <= n; i++) if (!color[i]) cout << i << ' ';
    } else {
        cout << blue << '\n';
        for (int i = 1; i <= n; i++) if (color[i]) cout << i << ' ';
    }
    cout << '\n';
    used.clear();
    color.clear();
    for (int i = 1; i <= n; i++) graph[i].clear();
    graph.clear();
    edges.clear();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}