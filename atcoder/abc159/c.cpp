#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    double n;
    cin >> n;
    double x = n / 3;
    cout << x * x * x << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/* Solution Notes {{{
    
    a = b = c = L / 3

}}} */