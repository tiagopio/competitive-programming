#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int a, b, cost;
};

int n, m;

void solve() {
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
        edges[i].a--, edges[i].b--;
    }
    vector<int> d(n, 0), p(n, -1);
    d[1] = 0;
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF) {
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                }
            }
        }
    }
    if (x == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        int y = x;
        for (int i = 0; i < n; i++) y = p[y];
        vector<int> cycle;
        for (int cur = y; ;cur = p[cur]) {
            cycle.push_back(cur);
            if (cur == y and cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto u : cycle) cout << u + 1 << ' ';
        cout << '\n';
    }
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