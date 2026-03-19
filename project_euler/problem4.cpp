#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ok(string &s) {
    int l = 0, r = s.length() - 1;
    while(l <= r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

void solve() {
    int sz = 0;
    int ans = 0;
    for (int a = 100; a <= 999; a++) {
        for (int b = 100; b <= 999; b++) {
            string s = to_string(a * b);
            if (ok(s)) {
                ans = max(ans, stoll(s));
            }
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