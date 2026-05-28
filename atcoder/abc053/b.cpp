#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') break;
        ans++;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'Z') break;
        ans++;
    }
    cout << s.length() - ans << '\n';
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
    ans = N - (leftmostAid + rightmostZid)
}}}*/