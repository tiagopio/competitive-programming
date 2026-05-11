#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+10;

vector<int> graph[N];
int ans[N];

void dfs(int s, int p) {
    for (auto u : graph[s]) {
        if (u != p) {
            dfs(u, s);
            ans[s] += ans[u] + 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        graph[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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