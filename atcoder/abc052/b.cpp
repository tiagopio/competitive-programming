#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0, x = 0;
    for (auto c : S) {
        if (c == 'D') x--;
        else x++;
        ans = max(ans, x);
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
    Simulate
}}}*/