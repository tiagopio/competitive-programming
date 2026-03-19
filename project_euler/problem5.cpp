#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int LCM = 1;
    for (int i = 1; i <= 20; i++) LCM = lcm(LCM, i);
    cout << LCM << '\n'; 
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