#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, K;

void solve() {
    cin >> N >> K;
    int pot = 1;
    for (int i = 0; i < N - 1; i++) pot *= K - 1; 
    cout << K * pot << '\n'; 
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
    for the first positon we can select 
    K colors
    for the other K - 1;
    ans = K * (K - 1) * (K - 1) * ... * (K - 1)
}}} */