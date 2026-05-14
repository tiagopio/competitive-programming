#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << ' ' << i + 2 << '\n';
            return;
        }
    }
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] != s[i + 1] and s[i] == s[i + 2]) {
            cout << i + 1 << ' ' << i + 3 << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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