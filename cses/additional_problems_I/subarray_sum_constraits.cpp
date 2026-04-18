#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 5e3+10;
 
using pii = pair<int, int>;
 
int n, m;
int pref[N];
bool used[N];
vector<pii> graph[N];
 
void dfs(int s, int v) {
    used[s] = true;
    pref[s] = v;
    for (auto [u, p] : graph[s]) {
        if (!used[u]) {
            dfs(u, v + p);
        } else {
            if (pref[u] != v + p) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        graph[l - 1].emplace_back(r, s);
        graph[r].emplace_back(l - 1, -s);
    }
    for (int i = 0; i <= n; i++) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << pref[i] - pref[i - 1] << ' ';
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