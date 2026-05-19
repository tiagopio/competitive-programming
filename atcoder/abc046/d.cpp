#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) if (s[i] == 'g') s[i] = 'r';
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i & 1) {
            if (s[i] == 'r') ans++;
        } else {
            if (s[i] == 'p') ans--;
        } 
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
    maximizing the number of p's
    rprprprprpr...rprpr..
}}} */