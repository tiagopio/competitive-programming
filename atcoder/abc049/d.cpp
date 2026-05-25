#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, K, L;
vector<bool> used;
vector<int> comp_roads, comp_rails;
vector<vector<int>> roads, rails;
vector<set<int>> groups_roads, groups_rails;

void dfs(int s, int comp, vector<int> &comp_v, vector<vector<int>> &graph) {
    used[s] = true;
    comp_v[s] = comp;
    for (auto u : graph[s]) {
        if (!used[u]) {
            dfs(u, comp, comp_v, graph);
        }
    }
}

void solve() {
    cin >> N >> K >> L;
    used.resize(N + 1, false);
    comp_roads.resize(N + 1);
    comp_rails.resize(N + 1);
    roads.resize(N + 1);
    rails.resize(N + 1);
    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        roads[p].push_back(q);
        roads[q].push_back(p);
    }
    for (int i = 0; i < L; i++) {
        int r, s;
        cin >> r >> s;
        rails[r].push_back(s);
        rails[s].push_back(r);
    }
    int comp = 1;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            dfs(i, comp, comp_roads, roads);
            comp++;
        }
    }
    groups_roads.resize(comp);
    comp = 1;
    used.assign(N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            dfs(i, comp, comp_rails, rails);
            comp++;
        }
    }
    groups_rails.resize(comp);
    for (int i = 1; i <= N; i++) groups_roads[comp_roads[i]].insert(i);
    for (int i = 1; i <= N; i++) groups_rails[comp_rails[i]].insert(i);
    used.assign(N + 1, false);
    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            set<int> inter;
            if (groups_roads[comp_roads[i]].size() < groups_rails[comp_rails[i]].size()) {
                for (auto u : groups_roads[comp_roads[i]]) {
                    if (groups_rails[comp_rails[i]].count(u)) inter.insert(u);
                }
            } else {
                for (auto u : groups_rails[comp_rails[i]]) {
                    if (groups_roads[comp_roads[i]].count(u)) inter.insert(u);
                }
            }
            for (auto u : inter) {
                ans[u] = inter.size();
                used[u] = true;
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    cout << '\n';
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
    We can map each component [roads/rails] to an ID and
    count the intersections between them.
}}}*/