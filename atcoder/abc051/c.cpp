#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for (int i = 0; i < abs(tx - sx); i++) cout << 'R';
    for (int i = 0; i < abs(ty - sy); i++) cout << 'U';
    for (int i = 0; i < abs(tx - sx); i++) cout << 'L';
    for (int i = 0; i < abs(ty - sy); i++) cout << 'D';
    cout << 'D';
    for (int i = 0; i < abs(tx - sx) + 1; i++) cout << 'R';
    for (int i = 0; i < abs(ty - sy) + 1; i++) cout << 'U';
    cout << 'L';
    cout << 'U';
    for (int i = 0; i < abs(tx - sx) + 1; i++) cout << 'L';
    for (int i = 0; i < abs(ty - sy) + 1; i++) cout << 'D';
    cout << "R\n";
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
    Walk in horizontal and vertical
}}}*/