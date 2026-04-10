#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 1e5+10;
 
int n, m;
bool used[N];
vector<int> orig[N], back[N];
 
void dfs1(int s) {
    used[s] = true;
    for (auto u : orig[s]) {
        if (!used[u]) dfs1(u);
    }
}
 
void dfs2(int s) {
    used[s] = true;
    for (auto u : back[s]) {
        if (!used[u]) dfs2(u);
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        orig[a].push_back(b);
        back[b].push_back(a);
    }
    dfs1(1);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << "NO\n";
            cout << 1 << ' ' << i << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++) used[i] = false;
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << "NO\n";
            cout << i << ' ' << 1 << '\n';
            return;
        }
    }
    cout << "YES\n";
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
