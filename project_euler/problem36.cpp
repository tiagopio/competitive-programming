#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int ans = 0;
    for (int i = 1; i < 1000000; i++) {
        string s = to_string(i);
        string bin;
        int x = i;
        while(x) {
            if (x % 2) bin.push_back('1');
            else bin.push_back('0');
            x /= 2;
        }
        string srev = s;
        string binrev = bin;
        reverse(srev.begin(), srev.end());
        reverse(binrev.begin(), binrev.end());
        if (s == srev and bin == binrev) ans += i;
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