#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("speeding");
    int n, m;
    cin >> n >> m;
    vector<int> road(110), bessie(110);
    int curr = 1;
    for (int i = 0; i < n; i++) {
        int s, v; 
        cin >> s >> v;
        while(s--) road[curr++] = v;
    }
    curr = 1;
    for (int i = 0; i < n; i++) {
        int s, v;
        cin >> s >> v;
        while(s--) bessie[curr++] = v;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) ans = max(ans, max(0LL, bessie[i] - road[i]));
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