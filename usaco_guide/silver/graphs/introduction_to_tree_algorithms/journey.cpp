#include <bits/stdc++.h>
using namespace std;

#define int long long

// li editorial

const int N = 1e5+10;

int n;
vector<int> graph[N];
double ans[N];

long double dfs(int s, int p = -1) {
    long double sum = 0;
    for (auto u : graph[s]) {
        if (u != p) {
            sum += dfs(u, s) + 1;
        }
    }
    return sum ? sum / (graph[s].size() - (p != -1)) : 0;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << fixed << setprecision(7) << dfs(1) << '\n';
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