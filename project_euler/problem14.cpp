#include <bits/stdc++.h>
using namespace std;

#define int long long

int collatz(int x) {
    if (x == 1) return 1;
    if (x & 1) return 1 + collatz(3 * x + 1);
    else return 1 + collatz(x / 2);
}

void solve() {
    int ans = 0, sz = 0;
    for (int i = 1; i < 1000000; i++) {
        if (collatz(i) > sz) {
            sz = collatz(i);
            ans = i;
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