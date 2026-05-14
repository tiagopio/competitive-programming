#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    cout << min(n, k) * x + (n - min(n, k)) * y << '\n'; 
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