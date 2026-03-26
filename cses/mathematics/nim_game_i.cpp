#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int xr = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        xr ^= x;
    } 
    if (!xr) cout << "second\n";
    else cout << "first\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}