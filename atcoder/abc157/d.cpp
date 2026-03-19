#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
    Disjoint Set Union
    1-indexed
    find: O(a(n)) ~= O(1) amortized
    unite: O(a(n)) ~= O(1) amortized
    components: O(1)
    max_size: O(1)
*/

struct DSU { 
    vector<int> parent, size;
    // largest component size, number of components
    int mx_size, comps;
    DSU(int n) : parent(n + 1), size(n + 1, 1), mx_size(-1), comps(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] = (parent[u] == u ? u : find(parent[u]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (size[u] > size[v]) swap(u, v);
        parent[u] = v, size[v] += size[u];
        mx_size = max(mx_size, size[v]);
        comps--;
    }

    int components() { return comps; }
    int max_size() { return mx_size; }
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> deg(N + 1, 0), block(N + 1, 0);
    DSU dsu(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        deg[u]++, deg[v]++;
        dsu.unite(u, v);
    }
    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        if (dsu.find(u) == dsu.find(v)) {
            dsu.unite(u, v);
            block[u]++, block[v]++;
        }
    }
    for (int i = 1; i <= N; i++) cout << (dsu.size[dsu.find(i)] - 1) - deg[i] - block[i] << ' ';
    cout << '\n';
}

auto main() -> signed {
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

    Assemble the DSU groups on the friendship edges.

    For the block edges, we only add if u, v are already part of the same group.

    The answer for each v will be:
    size[v] - 1 - deg[v] - block[v]

    O(N)
}}} */