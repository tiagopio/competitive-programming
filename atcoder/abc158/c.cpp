#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= 1000; i++) {
        if ((i * 8) / 100 == A and i / 10 == B) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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