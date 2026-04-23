#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        graph[a].emplace_back(b, c == 'S');
        graph[b].emplace_back(a, c == 'S');
    }
    int cmp = 0;
    bool ok = false;
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cmp++;
            queue<pair<int, bool>> q;
            q.emplace(i, true);
            while(!q.empty()) {
                pair<int, int> v = q.front();
                q.pop();
                color[v.first] = v.second;
                for (auto u : graph[v.first]) {
                    bool type = u.second ? v.second : !v.second;
                    if (color[u.first] == -1) {
                        q.emplace(u.first, type);
                    } else if (color[u.first] == !type) {
                        ok = true;
                        break;
                    }
                } 
            }
       }
    }
    if (ok) {
        cout << 0 << '\n';
    } else {
        cout << 1;
        for (int i = 0; i < cmp; i++) cout << 0;
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("revegetate");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}