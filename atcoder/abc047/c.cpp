#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S.length() - 1; i++) ans += S[i] != S[i + 1];
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

/* Solution Notes {{{
    count the number of S[i] != S[i + 1]
}}} */