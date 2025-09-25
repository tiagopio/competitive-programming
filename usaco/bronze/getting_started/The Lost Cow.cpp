#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("lostcow");
    int x, y;
    cin >> x >> y;
    bool turn = true;
    int curr = x, pot = 1, ans = 0;
    while(true) {
        int nw;
        if (turn) nw = x + pot;
        else nw = x - pot;
        if (y >= min(curr, nw) and y <= max(curr, nw)) {
            ans += abs(curr - y);
            break;
        }
        ans += abs(curr - nw);
        curr = nw;
        turn = !turn;
        pot <<= 1;
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