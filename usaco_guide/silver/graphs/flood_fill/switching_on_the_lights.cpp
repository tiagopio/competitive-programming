#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 110;

int n, m;

bool lit[MAX][MAX], used[MAX][MAX], skip[MAX][MAX];
vector<pair<int, int>> grid[MAX][MAX];

bool check(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < n and !used[i][j] and lit[i][j];
}

int steps[2][4] = {
    {0, 1, 0, -1},
    {1, 0, -1, 0}
};

void floodfill(int i, int j) {
    if (!check(i, j)) return;
    if (!skip[i][j]) for (auto [x, y] : grid[i][j]) lit[x][y] |= 1;
    skip[i][j] = true;
    used[i][j] = true;
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        grid[--x][--y].emplace_back(--a, --b);
    }
    int ans = 0;
    lit[0][0] = 1;
    int it = MAX * MAX;
    while(it--) {
        memset(used, 0, sizeof(used));
        floodfill(0, 0);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans += lit[i][j];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("lightson");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}