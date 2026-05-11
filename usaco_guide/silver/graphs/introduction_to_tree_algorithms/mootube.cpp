#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e3+10;

int n, q;
vector<pair<int, int>> graph[N];

void dfs(int s, int k, vector<bool> &used) {
    used[s] = true;
    for (auto [u, w] : graph[s]) {
        if (!used[u]) {
            if (w >= k) {
                dfs(u, min(w, k), used);
            }
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c); 
    }
    while(q--) {
        int k, v;
        cin >> k >> v;
        vector<bool> used(n + 1, false);
        dfs(v, k, used);
        cout << count(used.begin(), used.end(), true) - 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    setIO("mootube");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}