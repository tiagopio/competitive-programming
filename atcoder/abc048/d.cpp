#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == s[n - 1]) {
        if (n & 1) cout << "Second\n";
        else cout << "First\n";
    } else {
        if (n & 1) cout << "First\n";
        else cout << "Second\n";
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
    axaxa...xaxa
    axaxa...xaxb
}}} */