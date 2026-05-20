#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int W, H, N;
    cin >> W >> H >> N;
    int x1 = 0, y1 = 0, x2 = W, y2 = H;
    for (int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            x1 = max(x1, x);
        } else if (a == 2) {
            x2 = min(x2, x);
        } else if (a == 3) {
            y1 = max(y1, y);
        } else {
            y2 = min(y2, y);
        }
    }
    cout << max(0LL, (x2 - x1)) * max(0LL, (y2 - y1)) << '\n';
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
    We can just simulate the cuts and ajust the bottom
    left and top right coords
}}} */