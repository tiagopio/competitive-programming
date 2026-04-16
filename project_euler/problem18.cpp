#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 15;

int grid[N + 1][N + 1], dp[N + 1][N + 1];

bool check(int i, int j) {
    return i >= 0 and i < N and j >= 0 and j < N;
}

int f(int i, int j) {
    if (i == N - 1) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    if (check(i + 1, j)) dp[i][j] = max(dp[i][j], grid[i][j] + f(i + 1, j));
    if (check(i + 1, j + 1)) dp[i][j] = max(dp[i][j], grid[i][j] + f(i + 1, j + 1));
    return dp[i][j];
}

void solve() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> grid[i][j];
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << '\n';
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