#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 51;

int n, m;
char grid[MAX][MAX];
bool used[MAX][MAX];

bool check(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

void floodfill(int i, int j) {
    if (!check(i, j)) return;
    if (grid[i][j] == '#') return;
    if (used[i][j]) return;
    used[i][j] = true;
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            used[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                if (check(i + 1, j) and grid[i + 1][j] != 'G' and grid[i + 1][j] != 'B') grid[i + 1][j] = '#';
                if (check(i - 1, j) and grid[i - 1][j] != 'G' and grid[i - 1][j] != 'B') grid[i - 1][j] = '#';
                if (check(i, j + 1) and grid[i][j + 1] != 'G' and grid[i][j + 1] != 'B') grid[i][j + 1] = '#';
                if (check(i, j - 1) and grid[i][j - 1] != 'G' and grid[i][j - 1] != 'B') grid[i][j - 1] = '#';
            }
        }
    }
    floodfill(n - 1, m - 1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G') ok &= used[i][j];
            if (grid[i][j] == 'B') ok &= !used[i][j];
        }
    }
    cout << ((ok) ? "Yes\n" : "No\n");
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