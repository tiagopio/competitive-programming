#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
pair<int, int> pt[1010];
bool used[1010];

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dist(pair<int, int> &a, pair<int, int> &b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x * x + y * y;
}

void dfs(int s, int d) {
    used[s] = true;
    for (int i = 0; i < n; i++) {
        if (!used[i] and dist(pt[s], pt[i]) <= d) dfs(i, d);
    }
}

bool check(int M) {
    for (int i = 0; i < n; i++) used[i] = false;
    dfs(0, M);
    bool ok = true;
    for (int i = 0; i < n; i++) ok &= used[i];
    return ok;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pt[i].first >> pt[i].second;
    int l = 0, r = 1e9, ans = 0;
    while(l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setIO("moocast");

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
