#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int N, Ma, Mb;
int dp[41][401][401];
vector<tuple<int, int, int>> ch;

int f(int i, int j, int k) {
    if (i >= N) {
        if (j * Mb == k * Ma and j and k) return 0;
        return INF;
    }
    if (dp[i][j][k] != -1) return dp[i][j][k];
    auto [a, b, c] = ch[i];
    dp[i][j][k] = min(c + f(i + 1, j + a, k + b), f(i + 1, j, k));
    return dp[i][j][k];
}

void solve() {
    cin >> N >> Ma >> Mb;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ch.emplace_back(a, b, c);
    }
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 0, 0);
    cout << ((ans == INF) ? -1 : ans) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{
    dp[i][j][k] = min to make j / k
}}}*/