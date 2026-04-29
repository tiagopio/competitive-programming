#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX = 510;

int n, m, x, y;
int grid[MAX][MAX];
bool used[MAX][MAX], start[MAX][MAX];

bool check(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

void floodfill(int i, int j, int D, int last) {
    if (!check(i, j)) return;
    if (used[i][j]) return;
    if (abs(last - grid[i][j]) > D) return;
    used[i][j] = true;
    floodfill(i + 1, j, D, grid[i][j]);
    floodfill(i - 1, j, D, grid[i][j]);
    floodfill(i, j + 1, D, grid[i][j]);
    floodfill(i, j - 1, D, grid[i][j]);
}

bool check(int mid) {
    memset(used, 0, sizeof(used));
    floodfill(x, y, mid, grid[x][y]);
    bool ok = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (start[i][j]) ok &= (used[i][j]);
    return ok;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> start[i][j];
            if (start[i][j]) x = i, y = j;
        }
    }
    int l = 0, r = 1e10, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;  
        } else l = mid + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("ccski");

    int t = 1;
     //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}