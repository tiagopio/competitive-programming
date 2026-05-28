#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(A * B, C * D) << '\n';
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
    max(AB, CD)
}}}*/