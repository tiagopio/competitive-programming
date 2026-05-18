#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, h;
    cin >> a >> b >> h;
    cout << ((a + b) * h) / 2 << '\n';
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
    Trapezoid area = ((a + b) * h) / 2;
    since h is even the area always is integer
}}} */