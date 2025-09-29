#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("measurement");
    int n;
    cin >> n;
    vector<tuple<int, string, int>> a;
    map<string, int> mp;
    set<string> curr;
    for (int i = 0; i < n; i++) {
        int d;
        string cow;
        int chg;
        cin >> d >> cow >> chg;
        a.emplace_back(d, cow, chg);
        mp[cow] = 7;
    }
    sort(a.begin(), a.end());
    for (auto i : mp) curr.insert(i.first);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [d, cow, chg] = a[i];
        mp[cow] += chg;
        set<string> nw;
        int mxn = 0;
        for (auto j : mp) mxn = max(mxn, j.second);
        for (auto j : mp) {
            if (j.second == mxn) nw.insert(j.first);
        }
        if (curr != nw) {
            ans++;
            curr = nw;
        }
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