#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("shuffle");
    int n;
    cin >> n;
    vector<int> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> ans(n);
    vector<int> tmp(n);
    iota(tmp.begin(), tmp.end(), 0);
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < n; j++) {
            ans[a[j]] = tmp[j];
        }
        tmp = ans;
    }
    vector<string> ok(n);
    for (int i = 0; i < n; i++) ok[ans[i]] = b[i];
    for (auto i : ok) cout << i << '\n';
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