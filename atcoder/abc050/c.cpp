#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    int ans = 0;
    if (N & 1) {
        bool ok = true;
        ok &= (freq[0] == 1);
        for (auto [x, q] : freq) if (x) ok &= (q == 2 and (x % 2 == 0));
        if (ok) {
            ans = 1;
            for (auto [x, q] : freq) {
                ans *= q;
                ans %= mod;
            }
        }
    } else {
        bool ok = true;
        for (auto [x, q] : freq) ok &= (q == 2 and (x & 1));
        if (ok) {
            ans = 1;
            for (auto [x, q] : freq) {
                ans *= q;
                ans %= mod;
            }
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

/* Solution Notes {{{
    Evaluate the cases and the answer will
    be the product of frequences
}}}*/