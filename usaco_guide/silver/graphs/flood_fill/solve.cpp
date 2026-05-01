#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 110;

int n, k, r;
set<pair<int, int>> block[MAX][MAX];
int grid[MAX][MAX];
bool used[MAX][MAX];
vector<int> comps(MAX * MAX, 0);

bool check(int i, int j, int li, int lj) {
    return i >= 0 and i < n and j >= 0 and j < n and !used[i][j] and !block[li][lj].count({i, j});
}

void floodfill(int i, int j, int li, int lj, int c) {
    if (!check(i, j, li, lj)) return;
    used[i][j] = true;
    comps[c] += grid[i][j];
    floodfill(i + 1, j, i, j, c);
    floodfill(i - 1, j, i, j, c);
    floodfill(i + 1, j, i, j, c);
    floodfill(i + 1, j, i, j, c);
}

void solve() {
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        block[a][b].emplace(c, d);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        grid[a][b] = 1;
    }
    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j]) {
                floodfill(i, j, i, j, comp);
                comp++;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // setIO("countcross");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}