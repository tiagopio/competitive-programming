#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5+10;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int N, M;
int pos[MAXN], cmp[MAXN];
bool used[MAXN];
vector<int> graph[MAXN];
vector<tuple<int, int, int>> edges;

void dfs(int s, int c) {
    used[s] = true;
    cmp[s] = c;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u, c);
    }
}

bool check(int mid) {
    for (int i = 1; i <= N; i++) graph[i].clear();
    for (int i = 0; i <= mid; i++) {
        auto [w, a, b] = edges[i];
        graph[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        used[i] = false;
        cmp[i] = 0;
    }
    int comp = 1;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            dfs(i, comp);
            comp++;
        }
    }
    bool ok = true;
    for (int i = 1; i <= N; i++) ok &= (cmp[i] == cmp[pos[i]]);
    return ok;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> pos[i];
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(w, a, b);
        edges.emplace_back(w, b, a);
    }
    bool ok = true;
    for (int i = 1; i <= N; i++) ok &= (pos[i] == i);
    if (ok) {
        cout << -1 << '\n';
        return;
    }
    sort(edges.rbegin(), edges.rend());
    int l = 0, r = edges.size() - 1, ans = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    auto [w, a, b] = edges[ans];
    cout << w << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("wormsort");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
