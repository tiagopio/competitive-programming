#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int ans = 0;
    int n = 100;
    int s1 = n * (n + 1) / 2;
    int s2 = (n * (n + 1) * (2 * n + 1)) / 6;
    cout << s1 * s1 - s2 << '\n';
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