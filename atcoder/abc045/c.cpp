#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int pw = s.length() - 1;
    int ans = 0;
    for (int mask = 0; mask < (1ll << pw); mask++) {
        string tmp;
        tmp.push_back(s[0]);
        int id = 1;
        for (int j = 0; j <= pw; j++) {
            if ((1LL << j) & mask) {
                ans += stoll(tmp);
                tmp.clear();
                tmp.push_back(s[id]);
            } else {
                tmp.push_back(s[id]);
            }
            id++;
        }
        ans += stoll(tmp);
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
    We can consider the + as active bits
}}} */