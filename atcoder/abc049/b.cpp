#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];
    for (int i = 0; i < H; i++) cout << grid[i] << '\n' << grid[i] << '\n';
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
    duplicate the rows
}}}*/