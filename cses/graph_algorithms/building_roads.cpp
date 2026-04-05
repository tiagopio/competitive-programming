#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+10;

int n, m;
vector<int> graph[N];
bool used[N];
int c[N];

void dfs(int s, int color) {
    used[s] = true;
    c[s] = color;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u, color);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int color = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, color);
            color++;
        }
    }
    vector<pair<int, int>> ans;
    ans.emplace_back(1, c[1]);
    memset(used, 0, sizeof(used));
    used[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!used[c[i]]) {
            ans.emplace_back(i, c[i]);
            used[c[i]] = true;
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++) cout << ans[i].first << ' ' << ans[i + 1].first << '\n';
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
    
    We can count the number of connect components in
    the graph, the answer will be add an edge
    between every the components

    Complexity: O(n + m) dfs

    Task:	Building Roads
    Sender:	tiago
    Submission time:	2026-04-05 18:17:08 +0300
    Language:	C++ (C++20)
    Status:	READY
    Result:	ACCEPTED

}}} */