#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    vector<int> rec(26, 0);
    for (auto c : s) rec[c - 'a']++;
    bool ok = true;
    for (auto c : s) {
        if (c >= 'a' and c <= 'z') ok &= (rec[c - 'a'] % 2 == 0);
    }
    cout << ((ok) ? "Yes\n" : "No\n");
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