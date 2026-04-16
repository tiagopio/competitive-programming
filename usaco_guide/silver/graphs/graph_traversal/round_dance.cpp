#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> used;
vector<int> cmp, color, cmp_size, parent;
vector<vector<int>> orig, bid;
int cycle_start, cycle_end;

void find(int s, int c) {
    used[s] = true;
    cmp[s] = c;
    for (auto u : bid[s]) {
        if (!used[u]) find(u, c);
    }
}

bool dfs(int s) {
    color[s] = 1;
    for (auto u : orig[s]) {
        if (color[u] == 0) {
            parent[u] = s;
            if (dfs(u)) return true;
        } else if (color[u] == 1) {
            cycle_start = u;
            cycle_end = s;
            return true;
        }
    }
    color[s] = 2;
    return false;
}

void solve() {
    int n;
    cin >> n;
    used.resize(n + 1, false);
    cmp.resize(n + 1, 0);
    orig.resize(n + 1);
    bid.resize(n + 1);
    color.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        orig[i].push_back(x);
        bid[i].push_back(x);
        bid[x].push_back(i);
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            find(i, c);
            c++;
        }
    }
    vector<int> start(c, false);
    cmp_size.resize(c, 0);
    for (int i = 1; i <= n; i++) cmp_size[cmp[i]]++;
    int cycle = 0;
    for (int i = 1; i <= n; i++) used[i] = false;
    for (int i = 1; i <= n; i++) {
        if (!start[cmp[i]]) {
            if (dfs(i)) {
                vector<int> cycles;
                cycles.push_back(cycle_start);
                for (int v = cycle_end; v != cycle_start; v = parent[v]) cycles.push_back(v);
                cycles.push_back(cycle_start);
                cycle += cycles.size() > 3 and cycles.size() == cmp_size[cmp[i]] + 1;
            }
            start[cmp[i]] = true;
        }
    }
    cout << ((cycle == c - 1) ? cycle : cycle + 1) << ' ' << c - 1 << '\n';
    orig.clear();
    bid.clear();
    cmp.clear();
    used.clear();
    parent.clear();
    color.clear();
    cmp_size.clear();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}