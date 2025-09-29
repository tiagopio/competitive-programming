#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    setIO("censor");
    string s, t;
    cin >> s >> t;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        ans.push_back(s[i]);
        if (ans.length() >= t.length() and ans.substr(ans.length() - t.length()) == t) {
            ans.resize(ans.length() - t.length());
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