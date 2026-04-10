#include <bits/stdc++.h>
using namespace std;

int n, k;
bool used[21];
int ans[21];
vector<vector<int>> graph;
vector<int> color, p;

void dfs(int s, int p_) {
    used[s] = true;
    color[s] = 0;
    p[s] = p_;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u, s);
        else {
            if (color[u] == 0) {
                ans[u] = 1;
                int v = s;
                while(v != u) {
                    ans[v] = 1;
                    v = p[v];
                }
            }
        }
    }
    color[s] = 1;
}

void solve() {
    cin >> n >> k;
    graph.resize(n + 1);
    color.resize(n + 1);
    p.resize(n + 1);
    for (int i = 0; i < k; i++) {
        int a, b, s_a, s_b;
        cin >> a >> b >> s_a >> s_b;
        if (s_a > s_b) graph[a].push_back(b);
        else graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!used[i]) dfs(i, i);
    cout << count(ans, ans + n + 1, 1) << '\n';
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