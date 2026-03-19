#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int sum = 2, a = 1, b = 2;
    for (; ;) {
        int new_term = a + b;
        a = b;
        b = new_term;
        if (new_term > 4000000) break;
        if (new_term % 2 == 0) sum += new_term;
    }
    cout << sum << '\n';
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