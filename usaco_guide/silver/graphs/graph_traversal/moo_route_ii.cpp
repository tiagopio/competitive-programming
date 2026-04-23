#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        graph[c].emplace_back(r, s, d); 
    }
    vector<int> time(n + 1);
    for (int i = 1; i <= n; i++) cin >> time[i];
    for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
    vector<int> ans(n + 1, INF), minr(n + 1, INF);
    queue<pair<int, int>> q;
    minr[1] = 0;
    ans[1] = 0;
    q.emplace(1, 0);
    while(!q.empty()) {
        auto [u, t] = q.front();
        q.pop();
        int w = (u == 1) ? 0 : time[u];
        int rd = t + w;
        while(!graph[u].empty() and get<0>(graph[u].back()) >= rd) {
            auto [r, s, d] = graph[u].back();
            graph[u].pop_back();

            if (s < ans[d]) {
                ans[d] = s;
                q.emplace(d, s);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';
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