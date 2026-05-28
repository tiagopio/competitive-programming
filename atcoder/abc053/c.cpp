#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x;
    cin >> x;
    int ans = x / 11 * 2;
    x %= 11;
    while(x > 0) {
        x -= 6;
        ans++;
        if (x <= 0) break;
        x -= 5;
        ans++;
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

/* Solution Notes {{{
    Use 6 and 5 faces
}}}*/