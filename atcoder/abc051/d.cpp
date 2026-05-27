#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int N, M;
vector<vector<pair<int, int>>> graph;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater
    <pii>> q;
    q.emplace(0, s);
    while(!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) continue;
        for (auto u : graph[v]) {
            int to = u.first;
            int len = u.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.emplace(d[to], to);
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    graph.resize(N + 1);
    set<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
        edges.emplace(a, b);
    }
    vector<vector<int>> p(N + 1, vector<int>(N + 1, -1));
    for (int i = 1; i <= N; i++) {
        vector<int> d(N + 1, INF);
        dijkstra(i, d, p[i]);
    }
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            vector<int> path;
            int curr = b;
            while(curr != -1) {
                path.push_back(curr);
                int parent = p[a][curr];
                if (parent != -1) {
                    int u = min(parent, curr);
                    int v = max(parent, curr);
                    edges.erase({u, v});
                }
                curr = parent;
            }
        }
    }
    cout << edges.size() << '\n';
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
    Dijkstra and restore paths
}}}*/