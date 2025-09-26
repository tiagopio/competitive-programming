#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("blocks");
    int n;
    cin >> n;
    vector<int> rec(26, 0);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        vector<int> rec1(26, 0);
        vector<int> rec2(26, 0);
        for (auto j : a) rec1[j - 'a']++;
        for (auto j : b) rec2[j - 'a']++;
        for (int j = 0; j < 26; j++) rec[j] += max(rec1[j], rec2[j]);
    }
    for (auto i : rec) cout << i << '\n';
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