#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<int, int> mp;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    cout << ((mp[5] == 2 and mp[7] == 1) ? "YES\n" : "NO\n");
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}