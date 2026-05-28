#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5+10;

int N, A, B, dp[MAXN];
vector<int> X, a;

int f(int i) {
    if (i >= N - 1) return 0;
    if (dp[i] != -1) return dp[i];
    dp[i] = 0;
    dp[i] += min(f(i + 1) + A * a[i], f(i + 1) + B);
    return dp[i];
}

void solve() {
    cin >> N >> A >> B;
    memset(dp, -1, sizeof(dp));
    X.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) a.push_back(X[i + 1] - X[i]);
    cout << f(0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{
    dp[i] = min(f(i + 1) + a[i] * A, f(i + 1) + B)
}}}*/