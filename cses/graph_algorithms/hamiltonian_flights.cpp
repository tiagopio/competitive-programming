#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 20;
const int mod = 1e9+7;

int n, m;
int dp[N][1LL << N];
vector<vector<int>> graph;

int dfs(int s, int mask) {
    if (s == n - 1) return mask == ((1LL << n) - 1);
    if (dp[s][mask] != -1) return dp[s][mask];
    dp[s][mask] = 0;
    for (auto u : graph[s]) {
        if (!((1LL << u) & mask)) {
            dp[s][mask] += dfs(u, mask | (1LL << u));
            dp[s][mask] %= mod;
        }
    }
    return dp[s][mask];
}

void solve() {
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) <<'\n';
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