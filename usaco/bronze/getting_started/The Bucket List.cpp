#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("blist");
    int n;
    cin >> n;
    vector<int> rec(1010, 0);
    for (int i = 0; i < n; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        rec[s] += b;
        rec[t] -= b;
    }
    int ans = 0, sum = 0;
    for (int i = 0; i < 1010; i++) {
        sum += rec[i];
        ans = max(ans, sum);
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