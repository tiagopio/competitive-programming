#include <bits/stdc++.h>
using namespace std;

#define int long long

int ceil2(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n;
    cin >> n;
    int num = 1, den = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int div = max({1ll, ceil2(num, a), ceil2(den, b)});
        num = a * div;
        den = b * div;
    }
    cout << num + den << '\n';
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
    for each a/b find a * div >= num and b * div >= den 
}}} */