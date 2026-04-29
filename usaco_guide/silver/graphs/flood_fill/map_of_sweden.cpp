#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 510;

int n, m, ans = 0, q;
char grid[MAX][MAX];
int used[MAX][MAX];

bool check(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

void floodfill(int i, int j) {
    if (!check(i, j)) return;
    if (used[i][j]) return;
    if (grid[i][j] == '.') return;
    used[i][j] = 1;
    ans++;
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

void solve() {
    cin >> n >> m >> q;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }
    floodfill(x, y);
    cout << ans << '\n';
    while(q--) {
        int qx, qy;
        cin >> qx >> qy;
        qx--, qy--;
        grid[qx][qy] = '#';
        if (check(qx + 1, qy) and used[qx + 1][qy]) {
            floodfill(qx, qy);
        }
        if (check(qx - 1, qy) and used[qx - 1][qy]) {
            floodfill(qx, qy);
        }
        if (check(qx, qy + 1) and used[qx][qy + 1]) {
            floodfill(qx, qy);
        }
        if (check(qx, qy - 1) and used[qx][qy - 1]) {
            floodfill(qx, qy);
        }
        cout << ans << '\n';
    }
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