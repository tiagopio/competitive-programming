#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("shell");
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r, g;
        cin >> l >> r >> g;
        a.emplace_back(l, r, g);
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        vector<bool> game(4, false);
        game[i] = true;
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            auto [l, r, g] = a[j];
            swap(game[l], game[r]);
            tmp += (game[g]);
        }
        ans = max(ans, tmp);
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