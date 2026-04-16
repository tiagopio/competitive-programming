#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[21][21];

const int N = 21;

bool check(int i, int j) {
    return i >= 0 and i < N and j >= 0 and j < N;
}

int f(int i, int j) {
    cout << i << j << '\n';
    if (i == N - 1 and j == N - 1) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    if (check(i, j + 1)) dp[i][j] += f(i, j + 1);
    if (check(i + 1, j)) dp[i][j] += f(i + 1, j);
    return dp[i][j];
}

void solve() {
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