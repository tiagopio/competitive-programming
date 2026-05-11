#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4+10;

int n;
vector<int> graph[N];
bool used[N];

void dfs(int s) {
    used[s] = true;
    for (auto u : graph[s]) {
        if (!used[u]) dfs(u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
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