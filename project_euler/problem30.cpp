#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {    
    vector<int> ok;
    for (int i = 1; i <= 1e9; i++) {
        int x = i, sum = 0;
        while(x) {
            int d = x % 10;
            sum += d * d * d * d;
            x /= 10;
            }
        if (i == sum) {
            ok.push_back(i);
        }
    }
    cout << accumulate(ok.begin(), ok.end(), 0LL) - 1 << '\n';
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
