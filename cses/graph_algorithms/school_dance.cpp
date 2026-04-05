#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

struct Dinitz {
    struct Edge { int head, tail, cap, flow; };

    int n;
    vector<vector<int>> G;
    vector<Edge> edges;
    vector<int> level, last;

    Dinitz(int n_) : n(n_), G(n_) {};

    void add_edge(int u, int v, int w) {
        Edge a, b;
        a.head = u, b.head = v;
        a.tail = v, b.tail = u;
        a.cap = w, b.cap = 0;
        a.flow = 0, b.flow = 0;

        G[u].push_back(edges.size()); // edge index in the list
        edges.push_back(a); // real edges have even indexes
        G[v].push_back(edges.size()); // edge index in the list
        edges.push_back(b); // virtual edges have odd indexes
    }

    bool bfs(const int s, const int t) {
        last.assign(n, 0), level.assign(n, 0);
        level[s] = 1;
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int & i : G[u]) {
                    Edge & e = edges[i];
                    if((e.cap - e.flow) > 0 && level[e.tail] == 0) {
                    level[e.tail] = level[e.head] + 1;
                    q.push(e.tail);
                }
            }
        }
        return level[t]; // if reachable
    }

    int dfs(int neck, int u, const int t) {
        if(u == t) return neck;
        for(int & i = last[u]; i < G[u].size(); i++) {
            Edge & e = edges[G[u][i]];
            if((e.cap - e.flow) > 0 && level[e.tail] == (level[e.head] + 1)) {
                int flow = dfs(min(neck, (e.cap - e.flow)), e.tail, t);
                if(flow != 0) {
                    e.flow += flow;
                    edges[(G[u][i] ^ 1)].flow -= flow;
                    return flow;
                }
            }
        }
        return 0;
    }

    int max_flow(const int s, const int t) {
        for(Edge & e : edges) e.flow = 0;
            int flow = 0;
            while(bfs(s, t)) {
                while(int add = dfs(INF, s, t)) flow += add;
            }
            return flow;
    }
    
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int s = 0, t = n + m + 1;
    Dinitz D(n + m + 2);
    for (int i = 0; i < k; i++) {
        int b, g; cin >> b >> g;
        D.add_edge(b, n + g, 1);
    }
    for (int i = 1; i <= n; i++) D.add_edge(s, i, 1);
    for (int i = n + 1; i <= n + m; i++) D.add_edge(i, t, 1);
    cout << D.max_flow(s, t) << '\n';
    for (auto & edge : D.edges) {
        if ((edge.flow == 1) and (edge.head != s) and (edge.tail != t)) {
            cout << edge.head << ' ' << (edge.tail - n) << '\n';
        }
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