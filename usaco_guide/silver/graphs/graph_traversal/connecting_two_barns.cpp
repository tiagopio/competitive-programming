#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 1e5+10;

int comp[mxN];
vector<int> graph[mxN], comps[mxN];

void dfs(int cur, int c) {
    if (comp[cur] != -1) return;
    comp[cur] = c;
    for (auto u : graph[cur]) dfs(u, c);
}

int cost(int a, int b) {
    int dist = mxN;
    for (int u : comps[a]) {
        int i = lower_bound(comps[b].begin(), comps[b].end(), u) - comps[b].begin();
        if (i > 0) dist = min(dist, abs(comps[b][i - 1] - u));
        if (i < comps[b].size()) dist = min(dist, abs(comps[b][i] - u));
    }
    return dist * dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        comp[i] = -1;
        graph[i].clear();
        comps[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) { dfs(i, ++cur); }
    }
    for (int i = 0; i < n; i++) comps[comp[i]].push_back(i);
    int ans = cost(comp[0], comp[n - 1]);
    for (int c = 1; c < cur; c++) {
        ans = min(ans, cost(c, comp[0]) + cost(c, comp[n - 1]));
    }
    cout << ans << '\n';
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