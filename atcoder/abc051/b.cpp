#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int K, S;
    cin >> K >> S;
    int ans = 0;
    for (int X = 0; X <= K; X++) {
        for (int Y = 0; Y <= K; Y++) {
            if (S >= (X + Y) and S - (X + Y) <= K) ans++;
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
    brute force all possible triplets
}}}*/