#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    for (int i = 1; i <= 500; i++) {
        for (int j = i + 1; j <= 500; j++) {
            for (int k = j + 1; k <= 500; k++) {
                if (i * i + j * j == k * k and i + j + k == 1000) {
                    cout << i * j * k << '\n';
                }
            }
        }
    }
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