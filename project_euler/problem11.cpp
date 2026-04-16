#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 20;

bool check(int i, int j) {
    return i >= 0 and i < N and j >= 0 and j < N;
}

void solve() {
    int grid[N][N];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> grid[i][j];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check(i, j) and check(i, j + 1) and check(i, j + 2) and check(i, j + 3)) {
                ans = max(ans, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
            }
            if (check(i, j) and check(i + 1, j) and check(i + 2, j) and check(i + 3, j)) {
                ans = max(ans, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
            }
            if (check(i, j) and check(i + 1, j + 1) and check(i + 2, j + 2) and check(i + 3, j + 3)) {
                ans = max(ans, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);
            }
            if (check(i, j) and check(i + 1, j - 1) and check(i + 2, j - 2) and check(i + 3, j - 3)) {
                ans = max(ans, grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3]);
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