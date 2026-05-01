#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;
char grid[110][11];
int comp[110][11];
bool used[110][11];

bool check(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < 10 and !used[i][j];
}

void floodfill(int i, int j, int color, char c) {
    if (!check(i, j)) return;
    if (grid[i][j] != c) return; 
    used[i][j] = true;
    comp[i][j] = color;
    floodfill(i + 1, j, color, c);
    floodfill(i - 1, j, color, c);
    floodfill(i, j + 1, color, c);
    floodfill(i, j - 1, color, c);
}

bool mooyoo() {
    int color = 0;
    memset(used, false, sizeof(used));
    memset(comp, 0, sizeof(comp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] > '0' and !used[i][j]) {
                color++;
                floodfill(i, j, color, grid[i][j]);
            }
        }
    }
    vector<vector<pair<int, int>>> sz(color + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (comp[i][j] > 0) sz[comp[i][j]].emplace_back(i, j);
        }
    }
    bool ok = false;
    for (int i = 0; i < sz.size(); i++) {
        if (sz[i].size() >= k) {
            ok = true;
            for (auto [x, y] : sz[i]) grid[x][y] = 0;
        }
    }
    vector<vector<char>> tmp(n, vector<char>(10, '0'));
    for (int c = 0; c < 10; c++) {
        int r = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][c] >= '0') tmp[r--][c] = grid[i][c];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < 10; j++) grid[i][j] = tmp[i][j];
    return ok;
}

void solve() { 
    cin >> n >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < 10; j++) cin >> grid[i][j];
    while(mooyoo());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("mooyomooyo");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}