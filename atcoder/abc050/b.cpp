#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N;
    cin >> N;
    vector<int> T(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> T[i];
    int M;
    cin >> M;
    int sum = accumulate(T.begin(), T.end(), 0LL);
    while(M--) {
        int P, X;
        cin >> P >> X;
        cout << sum - T[P] + X << '\n';
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

/* Solution Notes {{{
    simulate the process
}}}*/