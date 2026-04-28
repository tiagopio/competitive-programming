#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1010;

int n, m;
char grid[MAXN][MAXN];
int used[MAXN][MAXN];

void floodfill(int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m or used[i][j] or grid[i][j] == '#') return;
    used[i][j] = 1;
    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1); 
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] and grid[i][j] == '.') {
                ans++;
                floodfill(i, j);
            }
        }
    }
    cout << ans << '\n';
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