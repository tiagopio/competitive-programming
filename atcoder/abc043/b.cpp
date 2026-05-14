#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') ans.push_back('0');
        else if (s[i] == '1') ans.push_back('1');
        else if (ans.size()) ans.pop_back();
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