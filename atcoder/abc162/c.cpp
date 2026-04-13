#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int k;
    cin >> k;
    int ans = 0;
    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= k; b++) {
            for (int c = 1; c <= k; c++) {
                ans += __gcd(__gcd(a, b), c);
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