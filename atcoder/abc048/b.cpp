#include <bits/stdc++.h>
using namespace std;

#define int long long

int a, b, x;

int f(int n) {
    if (n < 0) return 0;
    return n / x + 1;
}

void solve() {
    cin >> a >> b >> x;
    cout << f(b) - f(a - 1) << '\n';
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
    b / x - max(0, a - 1) / x + 1;
 }}} */